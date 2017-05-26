#include "ConstantProbabilityInfectionProcess.h"
#include "Colonization.h"

ConstantProbabilityInfectionProcess::ConstantProbabilityInfectionProcess(double prob) : _prob(prob)
{
}

bool ConstantProbabilityInfectionProcess::infectionProcess(double current_time, Agent & agent, Colonization & colonization)
{

    Properties & agentProperties = agent.properties();

    bool tested = true;
    if (agentProperties.get("ConstantProbabilityInfectionProcess_tested", tested)) {
        return false;
    }

    agentProperties.set("ConstantProbabilityInfectionProcess_tested", tested);

    boost::bernoulli_distribution<double> bs(_prob);
    double sample = bs(_random_generator);
    if (sample > 0.0) {
        colonization.setSympthomatic(true);
        return true;
    }
    return false;
}
