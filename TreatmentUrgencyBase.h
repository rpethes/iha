#ifndef TREATMENTURGENCYBASE_H
#define TREATMENTURGENCYBASE_H

#include <memory>

class TreatmentUrgencyBase
{
protected:
    double _lastTreatmentTime;
public:
    TreatmentUrgencyBase(double lastTreatmentTime);
    virtual ~TreatmentUrgencyBase();
    void setLastTreatmenTime(double lastTreatmentTime);
    double lastTreatmentTime() const;
    virtual double urgency(double current_time) const = 0 ;
    virtual TreatmentUrgencyBase * clone() = 0;
};

typedef std::shared_ptr<TreatmentUrgencyBase> typeTreatmentUrgencyBasePtr;
#endif // TREATMENTURGENCYBASE_H
