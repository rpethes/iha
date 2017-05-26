#ifndef DEFAULTSIMULATIONINITIALIZER_H
#define DEFAULTSIMULATIONINITIALIZER_H

#include "SimulationInitializerBase.h"
#include "defs.h"
#include "HCWFactory.h"
#include "PatientFactory.h"
#include "DistrSampler.h"

class DefaultSimulationInitializer : public SimulationInitializerBase
{
protected:
    int _nr_of_hcws;
    typeTreatmentList _defaultPatientTreatments;
    typeUIntSet _treatmentIDSet;
    typeUIntList  _wardIDList;
    typeHCWFactoryPtr _hcw_factory;
    typePatientFactoryPtr _patientFactory;
    typeDistrSamplerPtr _los_sampler;

public:
    DefaultSimulationInitializer(int nr_of_hcws,
                                 const typeTreatmentList & defaultPatientTreatments,
                                 const typeUIntSet & treatmentIDSet,
                                 const typeUIntList & wardIDList,
                                 typeHCWFactoryPtr hcw_factory,
                                 typePatientFactoryPtr patientFactory,
                                 typeDistrSamplerPtr los_sampler);

    virtual ~DefaultSimulationInitializer();
    virtual void initHCWDB(ObjectDB & hcwDB, typeWardList & wardList);
    virtual void initPatientDB(ObjectDB & patientDB, typeWardList & wardList);
};

#endif // DEFAULTSIMULATIONINITIALIZER_H
