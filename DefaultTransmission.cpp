#include "DefaultTransmission.h"
#include "log.h"
#include "HCWToPatientColonizationEvent.h"
#include "PatientToHCWColonizationEvent.h"
#include "RegisterProvider.h"

bool DefaultTransmission::transmission(double current_time, double contact_length, ColonizationType cType, Agent & src, Agent & target, Colonization & colonizaton)
{
    typePathogenPtr pathogen = colonizaton.pathogen();
    unsigned int pathogen_id = pathogen->id();

    if (!target.isColonizedWith(pathogen_id)) {
        typeTransmissionProbabilityBasePtr  transmissionProbability = pathogen->transmissionProbability();
        double transmission_probability = transmissionProbability->probability(contact_length);
        boost::bernoulli_distribution<double> bs(transmission_probability);
        double sample = bs(_random_generator);
        if (sample > 0.0) {
            Colonization * new_colonization = new Colonization(pathogen, current_time, cType, src.id());
            target.addColonization(new_colonization);
            if (cType == ctPatient) {
                LOG << "Transmission: time: " << current_time << " pathogen: " << pathogen->name() << " From patient: " << src.id() << " To HCW:" << target.id();
            } else {
                LOG << "Transmission: time: " << current_time << " pathogen: " << pathogen->name() << " From hcw: " << src.id() << " To patient:" << target.id();
            }
            return true;
        }
    }
    return false;
}

typeEventPtrList DefaultTransmission::transmission(double current_time, TreatmentAssign & treatmentAssign)
{

    typeEventPtrList transmissionEventList;
    Patient & patient = treatmentAssign.patient();
    typeHCWPtrList & hcws = treatmentAssign.hcws();
    Treatment & treatment = treatmentAssign.treatment();
    double contact_length = current_time - treatment.startTime();
    typeColonizationMap & patientColonizationMap = patient.colonizationMap();

    //***********  transmission from patient to HCW *****************
    typeColonizationMap::iterator it = patientColonizationMap.begin();
    typeColonizationMap::iterator end = patientColonizationMap.end();

    for (; it != end; ++it) {
        typeHCWPtrList::iterator iHCW = hcws.begin(), endHCW = hcws.end();
        for (; iHCW != endHCW; ++iHCW) {
            HCW * hcw = *iHCW;
            Colonization * colonization = it->second;
            if (transmission(current_time, contact_length, ctPatient, patient, *hcw, *colonization)) {
                typeEventPtr patientToHCWTransmissionEvent =
                PatientToHCWColonizationEvent::createEvent(current_time,
                                                           colonization->pathogen()->name().c_str(),
                                                           patient.id(),
                                                           hcw->id());
                transmissionEventList.push_back(patientToHCWTransmissionEvent);

            }

        }
    }

    //***********  transmission from HCW to patient *****************

    typeHCWPtrList::iterator iHCW = hcws.begin(), endHCW = hcws.end();

    for (; iHCW != endHCW; ++iHCW) {
        HCW * hcw = *iHCW;
        typeColonizationMap & hcwColonizationMap = hcw->colonizationMap();
        it = hcwColonizationMap.begin();
        end = hcwColonizationMap.end();
        for (; it != end; ++it) {
            Colonization * colonization = it->second;
            if (transmission(current_time, contact_length, ctHCW, *hcw, patient, *colonization)) {
                typeEventPtr hcwToPatientTransmissionEvent =
                HCWToPatientColonizationEvent::createEvent(current_time,
                                                           colonization->pathogen()->name().c_str(),
                                                           patient.id(),
                                                           hcw->id());
                transmissionEventList.push_back(hcwToPatientTransmissionEvent);
            }
        }
    }

    return transmissionEventList;

}


