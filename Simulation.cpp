#include "Simulation.h"
#include <iostream>
#include "SimulationTimer.h"
#include "log.h"
#include "InfectionProcessBase.h"
#include "InfectionEvent.h"
#include "RegisterProvider.h"

Simulation::Simulation(int simulation_days,
                       typeSimulationInitializerBasePtr simulationInitializer,
                       const typeWardList & wards,
                       typePatientModifPtr patientModif,
                       const typeTreatmentList & defaultTreatments,
                       typeDischargePtr discharge,
                       typeTreatmentSchedulerBasePtr treatmentScheduler,
                       typeTreatmentProcessingBasePtr treatmentProcessing,
                       typeHCWDecolonizationProcessPtr hcwDecolonizationProcess,
                       double iterations_per_hour) :
    _simulation_days(simulation_days),
    _simulationInitializer(simulationInitializer),
    _wards(wards),
    _patientModif(patientModif),
    _defaultTreatments(defaultTreatments),
    _discharge(discharge),
    _treatmentScheduler(treatmentScheduler),
    _treatmentProcessing(treatmentProcessing),
    _hcwDecolonizationProcess(hcwDecolonizationProcess),
    _iterations_per_hour(iterations_per_hour)
{}

Simulation::~Simulation()
{
    typeWardList::iterator iWard = _wards.begin(), endWards = _wards.end();
    for (; iWard != endWards; ++iWard) {
        delete *iWard;
    }
    _wards.clear();
}

void Simulation::infectionProcess(double current_time)
{
    typeObjectDBMap & db = _patientDB.db();
    typeObjectDBMap::iterator it = db.begin(), end = db.end();

    for (; it != end; ++it) {
        Object * obj = it->second;
        Patient * patient = dynamic_cast<Patient*>(obj);
        if (patient == 0) {
            LOG << "Simulation::infectionProcess(): Invalid item type in ObjectDB";
        }
        // it is better if it crashes if patient is NULL
        typeColonizationMap & patientColoninations = patient->colonizationMap();
        typeColonizationMap::iterator iColonization = patientColoninations.begin();
        typeColonizationMap::iterator endColonization = patientColoninations.end();

        for (; iColonization != endColonization; ++iColonization) {
            Colonization * colonization = iColonization->second;
            typePathogenPtr  pathogen = colonization->pathogen();
            typeInfectionProcessBasePtr  infectionProcessObj = pathogen->infectionProcess();
            if (infectionProcessObj->infectionProcess(current_time, *patient, *colonization)) {
                typeEventPtr infectionEvent = InfectionEvent::createEvent(current_time, patient->id(), pathogen->name().c_str(), colonization->colonizationTime());
                RegisterProvider::instance().addEvent(infectionEvent);
            }
        }
    }

}

bool Simulation::run_simulation()
{
    LOG << "Start simulation";
    LOG << "Init patient DB";

    _simulationInitializer->initHCWDB(_hcwDB, _wards);
    _simulationInitializer->initPatientDB(_patientDB, _wards);

    SimulationTimer timer(_iterations_per_hour);
    while (timer.current_day() < _simulation_days) {
        double current_time = timer.current_time();
        LOG << "****************** Current time:" << timer.current_time() << " ******************";
        typeWardList::iterator iWard = _wards.begin(), endWards = _wards.end();
        for (; iWard != endWards; ++iWard ) {
            Ward * ward = *iWard;
            typeAdmissionPtr admission = ward->admission();
            admission->admission(current_time, _patientDB,*_patientModif, ward->wardID(), _defaultTreatments);
        }
        LOG << "Nr of patients after admission: " << _patientDB.const_db().size();
        typeTreatmentAssignList treatmentAssignList;
        _treatmentScheduler->doSchedule(current_time, _patientDB, _hcwDB, _treatedPatientDB, _workingHCWDB, treatmentAssignList);

        _treatmentProcessing->startNewTreatments(current_time, treatmentAssignList);
        _treatmentProcessing->processTreatments(current_time, _patientDB, _hcwDB, _treatedPatientDB, _workingHCWDB);

        infectionProcess(current_time);

        _discharge->discharge(current_time, _patientDB);
        LOG << "Nr of patients after discharge: " << _patientDB.const_db().size();

        _hcwDecolonizationProcess->decolonizationProcess(current_time, _hcwDB);
        timer.tick();
    }


    return true;
}
