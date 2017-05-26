#include "DefaultSimulationInitializer.h"
#include <limits>
#include "UniformDistrSampler.h"
#include "InitPatientEvent.h"
#include "RegisterProvider.h"
#include "InitHCWEvent.h"

DefaultSimulationInitializer::DefaultSimulationInitializer(int nr_of_hcws,
                                                           const typeTreatmentList & defaultPatientTreatments,
                                                           const typeUIntSet & treatmentIDSet,
                                                           const typeUIntList & wardIDList,
                                                           typeHCWFactoryPtr hcw_factory,
                                                           typePatientFactoryPtr patientFactory,
                                                           typeDistrSamplerPtr los_sampler):
    _nr_of_hcws(nr_of_hcws),
    _defaultPatientTreatments(defaultPatientTreatments),
    _treatmentIDSet(treatmentIDSet),
    _wardIDList(wardIDList),
    _hcw_factory(hcw_factory),
    _patientFactory(patientFactory),
    _los_sampler(los_sampler)

{}

DefaultSimulationInitializer::~DefaultSimulationInitializer()
{}

void DefaultSimulationInitializer::initHCWDB(ObjectDB & hcwDB, typeWardList & wardList)
{

   for (int i = 0; i < _nr_of_hcws; ++i) {
       HCW * hcw =_hcw_factory->create(0.0, std::numeric_limits<double>::max(), true, _treatmentIDSet, _wardIDList, hcwDB );
       RegisterProvider::instance().addEvent(InitHCWEvent::createEvent(0.0, hcw->id(), _wardIDList, _treatmentIDSet));
   }
}

void DefaultSimulationInitializer::initPatientDB(ObjectDB & patientDB, typeWardList & wardList)
{
    typeWardList::iterator itWard = wardList.begin(), endWard = wardList.end();
    for (; itWard != endWard; ++itWard) {
        Ward * ward = *itWard;
        int bed_nr = ward->bed_number();
        for (int i = 0; i < bed_nr; ++i) {
            double los = _los_sampler->sample()*24.0*60.0;
            UniformDistrSampler admission_time_sampler(-los, 0.0);
            double admission_time = admission_time_sampler.sample();
            double discharge_time = admission_time + los;
            Patient * patient =_patientFactory->create(ward->wardID(), admission_time, discharge_time, _defaultPatientTreatments, patientDB);
            RegisterProvider::instance().addEvent(InitPatientEvent::createEvent(admission_time, patient->id(), ward->wardID(),los));
        }
    }
}
