#ifndef TESTEXPERIMENTFIXTURE_H
#define TESTEXPERIMENTFIXTURE_H

#include "ExperimentFixtureBase.h"

class TestExperimentFixture : public ExperimentFixtureBase
{
public:
    TestExperimentFixture();
    virtual bool run();
};

#endif // TESTEXPERIMENTFIXTURE_H
