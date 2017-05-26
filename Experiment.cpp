#include "Experiment.h"
#include "RegisterProvider.h"
#include "DefaultEventRegister.h"
#include "DefaultEventFilter.h"

Experiment::Experiment(int simulationNr, const char * path, typeSimulationFactoryPtr simulationFactory) :
    _simulationNr(simulationNr),_path(path), _simulationFactory(simulationFactory)
{}

bool Experiment::run()
{
    DefaultEventFilter * eventFilter = new DefaultEventFilter();
    DefaultEventRegister * eventRegister = new DefaultEventRegister(_path.c_str(), "events", eventFilter);
    RegisterProvider::instance().set(eventRegister);


    for (int i = 0; i < _simulationNr; ++i) {
        RegisterProvider::instance().start();

        typeSimulationPtr simulation = _simulationFactory->createSimulation();
        simulation->run_simulation();

        RegisterProvider::instance().stop();
    }

    return true;
}
