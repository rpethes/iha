#ifndef HCW_H
#define HCW_H

#include "Agent.h"
#include "defs.h"


class HCW : public Agent
{
    friend class HCWFactory;

protected:
    double _start_shift_time;
    double _stop_shift_time;
    bool _is_working;
    unsigned int _patient_id;
    typeUIntSet _treatmentIDSet;
    typeUIntList _wardIDList;

    HCW(unsigned int id,
        double start_shift_time,
        double stop_shift_time,
        bool is_working,
        const typeUIntSet & treatmentIDSet,
        const typeUIntList & wardIDList);
public:

    virtual ~HCW();

    void setStartShiftTime(double start_shift_time);
    void setStopShiftTime(double stop_shift_time);
    void setIsWorking(bool is_working);
    void setPatientID(unsigned int id);
    const typeUIntSet & treatmentIDSet() const;
    const typeUIntList & wardIDList() const;
    bool isWorking() const;
    bool isAvailable() const;

    bool canDoTreatment(unsigned int treatmentID) const
    {
        return _treatmentIDSet.find(treatmentID) != _treatmentIDSet.end();
    }

};

#endif // HCW_H
