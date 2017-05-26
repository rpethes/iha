#include "DefaultTreatmentScheduler.h"
#include "Patient.h"
#include "TreatmentPatientPair.h"
#include <algorithm>

DefaultTreatmentScheduler::DefaultTreatmentScheduler(double urgency_threshold) :
    _urgency_threshold(urgency_threshold)
{}



void DefaultTreatmentScheduler::doSchedule(double current_time, ObjectDB & patientDB, ObjectDB & hcwDB, ObjectDB & treatedPatientDB, ObjectDB & workingHCWDB,  typeTreatmentAssignList & treatmentAssignList)
{
    typeTreatmentPatientPairArray treatmentPatientPairArray;
    typeObjectDBMap & patientDBMap = patientDB.db();

    typeObjectDBMap::iterator iPatient = patientDBMap.begin(), endPatient = patientDBMap.end();
    for (; iPatient != endPatient; ++iPatient) {
        Patient * patient = dynamic_cast<Patient *>(iPatient->second);
        typeTreatmentList::iterator iTreatment = patient->treatmentList().begin();
        typeTreatmentList::iterator endTreatment = patient->treatmentList().end();

        for (; iTreatment != endTreatment; ++iTreatment) {
            TreatmentPatientPair pair(&(*iTreatment), patient, current_time);
            if (pair.urgency() > _urgency_threshold) {
                treatmentPatientPairArray.push_back(pair);
            }
        }
    }

    // sort treatments according it's urgency
    std::sort(treatmentPatientPairArray.begin(), treatmentPatientPairArray.end());


    typeObjectPtrArray hcwArray = hcwDB.values();
    // suffle hcw array
    std::random_shuffle(hcwArray.begin(), hcwArray.end());
    // copy to list
    typeObjectPtrList hcwList(hcwArray.begin(), hcwArray.end());

    typeTreatmentPatientPairArray::iterator iTP = treatmentPatientPairArray.begin(), endTP = treatmentPatientPairArray.end();

    for (; iTP != endTP && !hcwList.empty(); ++iTP) {
        Treatment * treatment = iTP->treatment();
        Patient * patient = iTP->patient();

        //check if the patient already gets treatment
        if (treatedPatientDB.get(patient->id()) != 0) {
            continue;
        }

        unsigned int treatmentID = treatment->treatmentTypeID();
        typeObjectPtrList::iterator iHCW = hcwList.begin(), endHCW = hcwList.end();

        int hcw_need = treatment->nr_of_necessary_hcws();
        int hcw_found = 0;

        TreatmentAssign treatmentAssign(*patient, *treatment);

        while (iHCW!=endHCW && hcw_found < hcw_need) {
            HCW * hcw = dynamic_cast<HCW *>(*iHCW);
            if (hcw->canDoTreatment(treatmentID)) {
                treatmentAssign.addHCW(*hcw);
                ++hcw_found;
                iHCW = hcwList.erase(iHCW);
            } else {
                ++iHCW;
            }
        }

        typeHCWPtrList::iterator iFoundHCW = treatmentAssign.hcws().begin();
        typeHCWPtrList::iterator endFoundHCW = treatmentAssign.hcws().end();
        if (hcw_found != hcw_need) {
            std::copy(iFoundHCW, endFoundHCW, std::back_inserter(hcwList));
            continue;
        }

        patientDB.remove_and_get(patient->id());
        treatedPatientDB.set(patient);

        for (;iFoundHCW != endFoundHCW; ++iFoundHCW) {
            hcwDB.remove_and_get((*iFoundHCW)->id());
            workingHCWDB.set((*iFoundHCW));
        }

        treatmentAssignList.push_back(treatmentAssign);
    }


}
