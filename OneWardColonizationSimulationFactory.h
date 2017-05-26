#ifndef ONEWARDCOLONIZATIONSIMULATIONFACTORY_H
#define ONEWARDCOLONIZATIONSIMULATIONFACTORY_H

#include "SimulationFactory.h"


struct OneWardColonizationSimulationParameters
{
    int simulation_days;
    int nr_of_hcws;
    double treatmetPeriodDistrSigma;
    double treatmetPeriodDistrMu;
    double treatmentUrgencyParam;
    double losDistrSigma;
    double losDistrMu;
    double admissionProcessParam;
    double admissionColonizationParam;
    double transmissionParam;
    double infectionProcessRate;
    int initial_ward_size;
    double iterations_per_hour;
    double urgency_threshold;
    double hcw_decolonization_period;

    OneWardColonizationSimulationParameters() :
        simulation_days(100),
        nr_of_hcws(15),
        treatmetPeriodDistrSigma(2.24),
        treatmetPeriodDistrMu(2),
        treatmentUrgencyParam(3.0*60.0),
        losDistrSigma(24.0 * 5.7 * 60),
        losDistrMu(3 * 24 * 60),
        admissionProcessParam(1.0/ 180),
        admissionColonizationParam(0.15),
        transmissionParam(0.03),
        infectionProcessRate(0.1),
        initial_ward_size(15),
        iterations_per_hour(6),
        urgency_threshold(0.5),
        hcw_decolonization_period(24*60.0)
    {}
};

class OneWardColonizationSimulationFactory : public SimulationFactory
{
protected:
    OneWardColonizationSimulationParameters _params;
public:
    OneWardColonizationSimulationFactory(const OneWardColonizationSimulationParameters & params);
    virtual typeSimulationPtr createSimulation();
};

#endif // ONEWARDCOLONIZATIONSIMULATIONFACTORY_H
