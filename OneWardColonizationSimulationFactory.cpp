#include "OneWardColonizationSimulationFactory.h"

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
#include "LognormalDistrSampler.h"
#include "TreatmentUgrencyStep.h"
#include "PeriodicallyDecolonizationProcess.h"


OneWardColonizationSimulationFactory::OneWardColonizationSimulationFactory(const OneWardColonizationSimulationParameters & params) :
    _params(params)
{}

typeSimulationPtr OneWardColonizationSimulationFactory::createSimulation()
{
    typeHCWFactoryPtr hcwFactory(new HCWFactory());
    typePatientFactoryPtr patientFactory(new PatientFactory());

    TreatmentType anyTreatmentType(1, "any");

    //typeDistrSamplerPtr treatmetPeriodSampler(new AbsGaussDistrSampler(15, 1.0));
    //typeDistrSamplerPtr treatmetPeriodSampler(new LognormalDistrSampler(_params.treatmetPeriodDistrMu, _params.treatmetPeriodDistrSigma));
    typeDistrSamplerPtr treatmetPeriodSampler(new ExpDistrSampler(_params.treatmetPeriodDistrMu));

    // ki kell számolni:
    typeTreatmentUrgencyBasePtr treatmentUrgency( new TreatmentUgrencyStep(0.0, _params.treatmentUrgencyParam));

    Treatment defaultTreatment(anyTreatmentType.id(), treatmetPeriodSampler, treatmentUrgency);

    typeTreatmentList defaultTreatmentList;
    defaultTreatmentList.push_back(defaultTreatment);

    typeUIntSet treatmentIDSet;
    treatmentIDSet.insert(defaultTreatment.treatmentTypeID());

    typeDistrSamplerPtr losSampler1(new LognormalDistrSampler(_params.losDistrMu, _params.losDistrSigma));
    typeDistrSamplerPtr losSampler2(new LognormalDistrSampler(_params.losDistrMu, _params.losDistrSigma));


    typeDistrSamplerPtr waitingTimeSampler(new ExpDistrSampler(_params.admissionProcessParam));
    typeDistrSamplerPtr admissionColonizationSampler( new BernoulliDistrSampler(_params.admissionColonizationParam));

    typeTransmissionProbabilityBasePtr transmissionProbability( new ConstantTransmissionProbability(_params.transmissionParam));

    typeInfectionProcessBasePtr infectionProcess(new ConstantProbabilityInfectionProcess(_params.infectionProcessRate));


    typePathogenPtr pathogen(new Pathogen(1, "MRSA", transmissionProbability, infectionProcess));

    typeAdmissionColonizationPtrList admissionColonizationList;
    AdmissionColonization * admissionColonization = new AdmissionColonization(admissionColonizationSampler, pathogen);
    admissionColonizationList.push_back(admissionColonization);
    typeAdmissionPtr admission1( new Admission(patientFactory, losSampler1, admissionColonizationList, waitingTimeSampler, waitingTimeSampler->sample()));

    Ward * ward1 = new Ward(1, admission1, _params.initial_ward_size);
    typeWardList wardList;
    wardList.push_back(ward1);

    typeUIntList wardIDList;
    typeWardList::iterator itWard = wardList.begin(), endWard = wardList.end();
    for (; itWard != endWard; ++itWard) {
        wardIDList.push_back((*itWard)->wardID());
    }


    typeTransmissionBasePtr transmission( new DefaultTransmission());


    typeSimulationInitializerBasePtr simulationInitializer(new DefaultSimulationInitializer(_params.nr_of_hcws,
                                                                                     defaultTreatmentList,
                                                                                     treatmentIDSet,
                                                                                     wardIDList,
                                                                                     hcwFactory,
                                                                                     patientFactory,
                                                                                     losSampler2));

    typePatientModifPtr patientModif( new PatientModif());
    typeDischargePtr discharge(new Discharge());

    typeTreatmentSchedulerBasePtr treatmentScheduler(new DefaultTreatmentScheduler(_params.urgency_threshold));

    typeTreatmentProcessingBasePtr treatmentProcessing( new DefaultTreatmentProcessing(transmission));

    typeHCWDecolonizationProcessPtr hCWDecolonizationProcess( new PeriodicallyDecolonizationProcess(_params.hcw_decolonization_period));

    typeSimulationPtr simulation( new Simulation(_params.simulation_days,
                          simulationInitializer,
                          wardList,
                          patientModif,
                          defaultTreatmentList,
                          discharge,
                          treatmentScheduler,
                          treatmentProcessing,
                          hCWDecolonizationProcess,
                          _params.iterations_per_hour
                          ));

    return simulation;

}
