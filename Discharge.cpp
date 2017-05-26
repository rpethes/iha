#include "Discharge.h"
#include "Patient.h"
#include "DischargeEvent.h"
#include "RegisterProvider.h"


Discharge::Discharge()
{}

Discharge::~Discharge()
{}

void Discharge::discharge(double currentTime, ObjectDB & patientDB)
{
    typeObjectDBMap & db = patientDB.db();
    typeObjectDBMap::iterator it = db.begin(), end = db.end();

    while (it!=end) {
        Patient * patient = dynamic_cast<Patient*>(it->second);
        //crash is better if pateint is NULL
        if (patient->discharge_time() <= currentTime) {
            typeEventPtr dischargeEvent = DischargeEvent::createEvent(currentTime,*patient);
            RegisterProvider::instance().addEvent(dischargeEvent);
            typeObjectDBMap::iterator itErase = it++;
            db.erase(itErase);
        }else {
            ++it;
        }
    }
}
