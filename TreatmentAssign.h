#ifndef TREATMENTASSIGN_H
#define TREATMENTASSIGN_H

#include "Patient.h"
#include "HCW.h"
#include <list>
#include "utils.h"

typedef std::list<HCW *> typeHCWPtrList;

class TreatmentAssign
{
protected:
    Patient * _patient;
    typeHCWPtrList _hcws;
    Treatment * _treatment;
public:
    TreatmentAssign(Patient & patient, HCW & hcw, Treatment & treatment);
    TreatmentAssign(Patient & patient, Treatment & treatment);
    virtual ~TreatmentAssign();
    void addHCW(HCW & hcw);
    Patient & patient();
    typeHCWPtrList & hcws();
    Treatment & treatment();

};

typedef std::list<TreatmentAssign> typeTreatmentAssignList;

inline typeUIntList getHCWIDList(const typeHCWPtrList & hcws)
{
    typeUIntList hcw_id_list;
    typeHCWPtrList::const_iterator it = hcws.begin(), end = hcws.end();
    for (; it != end; ++it) {
        hcw_id_list.push_back((*it)->id());
    }
    return hcw_id_list;
}


#endif // TREATMENTASSIGN_H
