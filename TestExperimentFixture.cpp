#include "TestExperimentFixture.h"
#include "TestSimulationFactory.h"
#include "Experiment.h"

TestExperimentFixture::TestExperimentFixture()
{}

bool TestExperimentFixture::run()
{
    typeSimulationFactoryPtr simulationFactory(new TestSimulationFactory());

    Experiment experiment(10,"../EventLogs/Test/",  simulationFactory);

    return experiment.run();
}
