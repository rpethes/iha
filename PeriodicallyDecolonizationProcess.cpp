#include "PeriodicallyDecolonizationProcess.h"
#include "HCW.h"
#include "RegisterProvider.h"
#include "PeriodicallyHCWDecolonizationEvent.h"

const char * DECOLONIZATION_TIME = "DECOLONIZATION_TIME";

PeriodicallyDecolonizationProcess::PeriodicallyDecolonizationProcess(double decolonization_period):
    _decolonization_period(decolonization_period)
{}

void PeriodicallyDecolonizationProcess::decolonizationProcess(double current_time, ObjectDB & hcwDB)
{
    typeObjectDBMap & db = hcwDB.db();
    typeObjectDBMap::iterator it = db.begin(), end = db.end();

    for (; it != end; ++it) {
        Object * agent = it->second;
        HCW * hcw = dynamic_cast<HCW*>(agent);
        double last_decolonization_time = 0.0;
        hcw->properties().get(DECOLONIZATION_TIME, last_decolonization_time);
        if (current_time - last_decolonization_time > _decolonization_period) {
            hcw->removeAllColonization();
            hcw->properties().set(DECOLONIZATION_TIME, current_time);
            RegisterProvider::instance().addEvent(PeriodicallyHCWDecolonizationEvent::createEvent(current_time, hcw->id()));
        }

    }
}
