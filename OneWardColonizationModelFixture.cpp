#include "OneWardColonizationModelFixture.h"
#include "OneWardColonizationSimulationFactory.h"
#include "Experiment.h"

OneWardColonizationModelFixture::OneWardColonizationModelFixture()
{}

bool OneWardColonizationModelFixture::run()
{
    OneWardColonizationSimulationParameters params;

    params.simulation_days = 120;
    params.nr_of_hcws = 4;
    params.treatmetPeriodDistrSigma = 0.4723807271;
    //params.treatmetPeriodDistrMu = 2.1910133173;
    params.treatmetPeriodDistrMu = 1.0/10;
    params.treatmentUrgencyParam = 3.0*60.0;
    params.losDistrSigma = 0.3627345555;
    params.losDistrMu = 1.3205061822;
    params.admissionProcessParam = 1.0/ 180.0;
    params.admissionColonizationParam = 0.2;
    params.transmissionParam = 0.07;
    params.infectionProcessRate = 0.1;
    params.initial_ward_size = 15;
    params.iterations_per_hour = 6;
    params.urgency_threshold = 0.5,
    params.hcw_decolonization_period = 24*60.0;

    typeSimulationFactoryPtr simulationFactory(new OneWardColonizationSimulationFactory(params));

    Experiment experiment(100,"../EventLogs/OneWardSample/", simulationFactory);

    return experiment.run();
}
