#include "DefaultTreatmentProcessing.h"
#include "log.h"
#include "utils.h"
#include "RegisterProvider.h"
#include "TreatmentEvent.h"

DefaultTreatmentProcessing::DefaultTreatmentProcessing(typeTransmissionBasePtr transmission) :
    _transmission(transmission)
{}

void DefaultTreatmentProcessing::startNewTreatments(double current_time, typeTreatmentAssignList & newTreatments)
{
    typeTreatmentAssignList::iterator it= newTreatments.begin(), end = newTreatments.end();
    for (; it!= end; ++it) {
        _runningTreatments.push_back(*it);
        TreatmentAssign & ta = _runningTreatments.back();
        typeUIntList hcw_id_list = getHCWIDList(ta.hcws());
        LOG << "Start treatment. Treatment: " << ta.treatment().treatmentTypeID() <<" Patient: " << ta.patient().id() << " HCWs: " << iterableToString(hcw_id_list,";");
        ta.treatment().startTreatment(current_time);
    }
}

void DefaultTreatmentProcessing::processTreatments(double current_time, ObjectDB & patientDB, ObjectDB & hcwDB, ObjectDB & treatedPatientDB, ObjectDB & workingHCWDB)
{
    typeTreatmentAssignList::iterator it= _runningTreatments.begin(), end = _runningTreatments.end();
    while (it!= end) {
        TreatmentAssign & ta = *it;
        Treatment & treatment = ta.treatment();
        double stop_time = treatment.stopTime();
        if (treatment.isActive() && stop_time <= current_time) {            
            treatment.stopTreatment(stop_time);

            typeEventPtr treatmentEvent( TreatmentEvent::createEvent(treatment.startTime(),ta));

            Patient & patient = ta.patient();
            treatedPatientDB.remove_and_get(patient.id());
            patientDB.set(&patient);

            typeHCWPtrList & hcws = ta.hcws();
            typeHCWPtrList::iterator iHCW = hcws.begin(), endHCW = hcws.end();
            typeUIntList hcw_id_list;
            for (; iHCW != endHCW; ++iHCW) {
                HCW * hcw = *iHCW;
                workingHCWDB.remove_and_get(hcw->id());
                hcwDB.set(hcw);
                hcw_id_list.push_back(hcw->id());
            }
            typeEventPtrList transmissionEvents = _transmission->transmission(current_time, ta);
            if (!transmissionEvents.empty()) {
                RegisterProvider::instance().addSubEvents(treatmentEvent, transmissionEvents);
            }
            LOG << "Stop treatment. Treatment: " << ta.treatment().treatmentTypeID() <<" Patient: " << patient.id() << " HCWs: " << iterableToString(hcw_id_list,";");
            it = _runningTreatments.erase(it);

            RegisterProvider::instance().addEvent(treatmentEvent);
        }else {
            ++it;
        }
    }
}
