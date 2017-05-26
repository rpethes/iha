#ifndef PERIODICALLYDECOLONIZATIONPROCESS_H
#define PERIODICALLYDECOLONIZATIONPROCESS_H

#include "HCWDecolonizationProcess.h"


class PeriodicallyDecolonizationProcess : public HCWDecolonizationProcess
{
protected:
    double _decolonization_period;
public:
    PeriodicallyDecolonizationProcess(double decolonization_period);
    virtual void decolonizationProcess(double current_time, ObjectDB & hcwDB);
};



#endif // PERIODICALLYDECOLONIZATIONPROCESS_H
