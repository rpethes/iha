#include "TestSimulationFactory.h"

using namespace std;

#include "TreatmentType.h"
#include "AbsGaussDistrSampler.h"
#include "TreatmentUrgencyExp.h"
#include "PatientFactory.h"
#include "HCWFactory.h"
#include "ExpDistrSampler.h"
#include "BernoulliDistrSampler.h"
#include "DefaultTreatmentScheduler.h"
#include "DefaultTreatmentProcessing.h"
#include "DefaultTransmission.h"
#include "ConstantTransmissionProbability.h"
#include "ConstantProbabilityInfectionProcess.h"
#include "DefaultSimulationInitializer.h"
#include "PeriodicallyDecolonizationProcess.h"

TestSimulationFactory::TestSimulationFactory()
{}

typeSimulationPtr TestSimulationFactory::createSimulation()
{
    typeHCWFactoryPtr hcwFactory(new HCWFactory());
    typePatientFactoryPtr patientFactory(new PatientFactory());

    int simulation_days = 100;
    int nr_of_hcws = 5;

    TreatmentType anyTreatmentType(1, "any");
    //ide valami hatványeloszlás kell:
    typeDistrSamplerPtr treatmetPeriodSampler(new AbsGaussDistrSampler(10, 1.0));

    // ki kell számolni:
    typeTreatmentUrgencyBasePtr treatmentUrgency( new TreatmentUrgencyExp(0.0, 0.01));

    Treatment defaultTreatment(anyTreatmentType.id(), treatmetPeriodSampler, treatmentUrgency);

    typeTreatmentList defaultTreatmentList;
    defaultTreatmentList.push_back(defaultTreatment);

    typeUIntSet treatmentIDSet;
    treatmentIDSet.insert(defaultTreatment.treatmentTypeID());

    typeDistrSamplerPtr losSampler1(new AbsGaussDistrSampler(24.0 * 3 * 60, 24 * 60));
    typeDistrSamplerPtr losSampler2(new AbsGaussDistrSampler(24.0 * 3 * 60, 24 * 60));
    typeDistrSamplerPtr waitingTimeSampler(new ExpDistrSampler(1.0/ 180));
    typeDistrSamplerPtr admissionColonizationSampler( new BernoulliDistrSampler(0.1));

    typeTransmissionProbabilityBasePtr transmissionProbability( new ConstantTransmissionProbability(0.3));

    typeInfectionProcessBasePtr infectionProcess(new ConstantProbabilityInfectionProcess(0.1));


    typePathogenPtr pathogen(new Pathogen(1, "ANY", transmissionProbability, infectionProcess));

    typeAdmissionColonizationPtrList admissionColonizationList;
    AdmissionColonization * admissionColonization = new AdmissionColonization(admissionColonizationSampler, pathogen);
    admissionColonizationList.push_back(admissionColonization);
    typeAdmissionPtr admission1( new Admission(patientFactory, losSampler1, admissionColonizationList, waitingTimeSampler, waitingTimeSampler->sample()));

    Ward * ward1 = new Ward(1, admission1, 15);
    typeWardList wardList;
    wardList.push_back(ward1);

    typeUIntList wardIDList;
    typeWardList::iterator itWard = wardList.begin(), endWard = wardList.end();
    for (; itWard != endWard; ++itWard) {
        wardIDList.push_back((*itWard)->wardID());
    }


    typeTransmissionBasePtr transmission( new DefaultTransmission());


    typeSimulationInitializerBasePtr simulationInitializer(new DefaultSimulationInitializer(nr_of_hcws,
                                                                                     defaultTreatmentList,
                                                                                     treatmentIDSet,
                                                                                     wardIDList,
                                                                                     hcwFactory,
                                                                                     patientFactory,
                                                                                     losSampler2));

    typePatientModifPtr patientModif( new PatientModif());
    typeDischargePtr discharge(new Discharge());

    double iterations_per_hour = 6;

    typeTreatmentSchedulerBasePtr treatmentScheduler(new DefaultTreatmentScheduler(0.5));

    typeTreatmentProcessingBasePtr treatmentProcessing( new DefaultTreatmentProcessing(transmission));

    typeHCWDecolonizationProcessPtr hCWDecolonizationProcess( new PeriodicallyDecolonizationProcess(12*60.0));


    typeSimulationPtr simulation( new Simulation(simulation_days,
                          simulationInitializer,
                          wardList,
                          patientModif,
                          defaultTreatmentList,
                          discharge,
                          treatmentScheduler,
                          treatmentProcessing,
                          hCWDecolonizationProcess,
                          iterations_per_hour
                          ));

    return simulation;

}
