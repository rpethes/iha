#include "DefaultCohortStrategy.h"
#include <iostream>
#include <typeinfo>
#include "HCW.h"

typeUIntList DefaultCohortStrategy::availableHCWs(const ObjectDB & hcwDB, unsigned int patientID)
{
    typeUIntList availableHCWList;
    const typeObjectDBMap & db = hcwDB.const_db();
    typeObjectDBMap::const_iterator it = db.begin(), end = db.end();
    for (; it != end; ++it) {
        Object * obj = it->second;
        const HCW * hcw = dynamic_cast<const HCW *>(obj);
        if (hcw == 0) {
            std::cerr << "Critical error in typeUIntList DefaultCohortStrategy::availableHCWs(const ObjectDB & hcwDB, unsigned int patientID)";
            std::cerr << "hcwDB must contain HCW * objects";
            throw std::bad_cast();
        }
        if (hcw->isAvailable()) {
            availableHCWList.push_back(hcw->id());
        }
    }
    return availableHCWList;
}

void DefaultCohortStrategy::patientAdmission(Patient & patient, ObjectDB & hcwDB)
{
    // DO NOTHING
}

void DefaultCohortStrategy::patientDischarge(Patient & patient)
{
    // DO NOTHING
}
