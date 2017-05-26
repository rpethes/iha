#include "TreatmentAssign.h"

TreatmentAssign::TreatmentAssign(Patient & patient, HCW & hcw, Treatment & treatment)
{
    _patient = & patient;
    _hcws.push_back(&hcw);
    _treatment = & treatment;
}

TreatmentAssign::TreatmentAssign(Patient & patient, Treatment & treatment) :
    _patient(&patient), _treatment(&treatment)
{}

TreatmentAssign::~TreatmentAssign()
{
    // nothing to do
}

void TreatmentAssign::addHCW(HCW & hcw)
{
    _hcws.push_back(&hcw);
}

Patient & TreatmentAssign::patient()
{
    return *_patient;
}

typeHCWPtrList & TreatmentAssign::hcws()
{
    return _hcws;
}

Treatment & TreatmentAssign::treatment()
{
    return *_treatment;
}
