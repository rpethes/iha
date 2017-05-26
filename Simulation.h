#ifndef SIMULATION_H
#define SIMULATION_H

#include "SimulationTimer.h"
#include "ObjectDB.h"
#include "SimulationInitializerBase.h"
#include "Ward.h"
#include "PatientModif.h"
#include "Treatment.h"
#include "Discharge.h"
#include "TreatmentSchedulerBase.h"
#include "TreatmentProcessingBase.h"
#include "TransmissionBase.h"
#include "HCWDecolonizationProcess.h"

class Simulation
{
protected:
    int _simulation_days;
    ObjectDB _hcwDB;
    ObjectDB _patientDB;
    ObjectDB _workingHCWDB;
    ObjectDB _treatedPatientDB;
    typeSimulationInitializerBasePtr _simulationInitializer;
    typeWardList _wards;
    typePatientModifPtr _patientModif;
    typeTreatmentList  _defaultTreatments;
    typeDischargePtr _discharge;
    typeTreatmentSchedulerBasePtr  _treatmentScheduler;
    typeTreatmentProcessingBasePtr  _treatmentProcessing;
    typeHCWDecolonizationProcessPtr _hcwDecolonizationProcess;
    double _iterations_per_hour;

    virtual void infectionProcess(double current_time);
public:
    Simulation(int simulation_days,
               typeSimulationInitializerBasePtr simulationInitializer,
               const typeWardList & wards,
               typePatientModifPtr patientModif,
               const typeTreatmentList & defaultTreatments,
               typeDischargePtr discharge,
               typeTreatmentSchedulerBasePtr treatmentScheduler,
               typeTreatmentProcessingBasePtr treatmentProcessing,
               typeHCWDecolonizationProcessPtr hcwDecolonizationProcess,
               double iterations_per_hour
               );

    virtual ~Simulation();

    virtual bool run_simulation();
};

typedef std::shared_ptr<Simulation> typeSimulationPtr;

#endif // SIMULATION_H
