#include "Admission.h"
#include "log.h"
#include "RegisterProvider.h"
#include "AdmissionEvent.h"
#include "AdmissionColonizationEvent.h"


Admission::Admission(typePatientFactoryPtr patientFactory,
                     typeDistrSamplerPtr losSampler,
                     typeAdmissionColonizationPtrList & admissionColonizationList,
                     typeDistrSamplerPtr admissionWaitingTimeSampler,
                     double next_admission_time) :
            _patientFactory(patientFactory),
            _losSampler(losSampler),
            _admissionColonizationList(admissionColonizationList),
            _admissionWaitingTimeSampler(admissionWaitingTimeSampler),
            _next_admission_time(next_admission_time)
{}

Admission::~Admission()
{
    typeAdmissionColonizationPtrList::iterator it = _admissionColonizationList.begin(), end = _admissionColonizationList.end();

    for (; it != end; ++it) {
        delete *it;
    }
    _admissionColonizationList.clear();
}

void Admission::admission(double current_time, ObjectDB & patientDB, PatientModif & patientModif, unsigned int ward_id, const typeTreatmentList & defaultTreatmentList)
{
    if (_next_admission_time <= current_time) {
        double los = _losSampler->sample()*24.0*60.0;
        double discharge_time = current_time + los;
        Patient * patient = _patientFactory->create(ward_id, current_time, discharge_time, defaultTreatmentList, patientDB);
        patientModif.modifyPatient(*patient);
        double waiting_time = _admissionWaitingTimeSampler->sample();
        _next_admission_time = current_time + waiting_time;
        LOG << "Patient admission: time: " << current_time << " ID: " << patient->id();
        typeAdmissionColonizationPtrList::iterator it = _admissionColonizationList.begin(), end = _admissionColonizationList.end();

        typeEventPtr admissionEvent = AdmissionEvent::createEvent(current_time, patient->id(), ward_id, los);

        for (; it != end; ++it) {
            AdmissionColonization * admissionColonization = *it;
            Colonization * colonization = admissionColonization->isColonized(current_time);
            if (colonization != 0) {
                patient->addColonization(colonization);
                LOG << "Admission colonization: " << colonization->pathogen()->name();

                typeEventPtr admissionColonizationEvent = AdmissionColonizationEvent::createEvent(current_time, colonization->pathogen()->name().c_str(), patient->id());
                RegisterProvider::instance().addSubEvent(admissionEvent, admissionColonizationEvent);

            }
        }

        RegisterProvider::instance().addEvent(admissionEvent);

    }
}

