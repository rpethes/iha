TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

DEFINES+= BOOST_LOG_DYN_LINK

SOURCES += main.cpp \
    Pathogen.cpp \
    TreatmentType.cpp \
    Colonization.cpp \
    Agent.cpp \
    TreatmentUrgencyBase.cpp \
    TreatmentUrgencyExp.cpp \
    GaussDistrSampler.cpp \
    AbsGaussDistrSampler.cpp \
    BernoulliDistrSampler.cpp \
    UniformDistrSampler.cpp \
    ExpDistrSampler.cpp \
    Treatment.cpp \
    Patient.cpp \
    PatientFactory.cpp \
    ObjectDB.cpp \
    HCW.cpp \
    HCWFactory.cpp \
    HCWShiftPolicyBase.cpp \
    DefaultCohortStrategy.cpp \
    AdmissionColonization.cpp \
    PatientModif.cpp \
    Admission.cpp \
    SimulationTimer.cpp \
    Discharge.cpp \
    Ward.cpp \
    DefaultSimulationInitializer.cpp \
    Simulation.cpp \
    log.cpp \
    TreatmentAssign.cpp \
    DefaultTreatmentScheduler.cpp \
    DefaultTreatmentProcessing.cpp \
    utils.cpp \
    DefaultTransmission.cpp \
    ConstantTransmissionProbability.cpp \
    Event.cpp \
    AdmissionEvent.cpp \
    ColonizationEvent.cpp \
    AdmissionColonizationEvent.cpp \
    DefaultEventRegister.cpp \
    RegisterProvider.cpp \
    TreatmentEvent.cpp \
    PatientToHCWColonizationEvent.cpp \
    HCWToPatientColonizationEvent.cpp \
    DischargeEvent.cpp \
    Variable.cpp \
    Properties.cpp \
    ConstantProbabilityInfectionProcess.cpp \
    InfectionEvent.cpp \
    TestSimulationFactory.cpp \
    Experiment.cpp \
    TestExperimentFixture.cpp \
    OneWardColonizationModelFixture.cpp \
    OneWardColonizationSimulationFactory.cpp \
    GammaDistrSampler.cpp \
    WeibullDistrSampler.cpp \
    LognormalDistrSampler.cpp \
    TreatmentUgrencyStep.cpp \
    HCWDecolonizationProcess.cpp \
    PeriodicallyDecolonizationProcess.cpp \
    PeriodicallyHCWDecolonizationEvent.cpp \
    InitPatientEvent.cpp \
    InitHCWEvent.cpp

HEADERS += \
    Object.h \
    Pathogen.h \
    TreatmentType.h \
    Colonization.h \
    Agent.h \
    TreatmentUrgencyBase.h \
    TreatmentUrgencyExp.h \
    DistrSampler.h \
    GaussDistrSampler.h \
    AbsGaussDistrSampler.h \
    BernoulliDistrSampler.h \
    UniformDistrSampler.h \
    ExpDistrSampler.h \
    Treatment.h \
    Patient.h \
    PatientFactory.h \
    ObjectDB.h \
    HCW.h \
    defs.h \
    HCWFactory.h \
    HCWShiftPolicyBase.h \
    CohortStrategyBase.h \
    DefaultCohortStrategy.h \
    AdmissionColonization.h \
    PatientModif.h \
    Admission.h \
    SimulationTimer.h \
    Discharge.h \
    Ward.h \
    SimulationInitializerBase.h \
    DefaultSimulationInitializer.h \
    Simulation.h \
    log.h \
    TreatmentAssign.h \
    DefaultTreatmentScheduler.h \
    TreatmentPatientPair.h \
    TreatmentSchedulerBase.h \
    TreatmentProcessingBase.h \
    DefaultTreatmentProcessing.h \
    utils.h \
    TransmissionBase.h \
    DefaultTransmission.h \
    ConstantTransmissionProbability.h \
    TransmissionProbabilityBase.h \
    Event.h \
    AdmissionEvent.h \
    ColonizationEvent.h \
    AdmissionColonizationEvent.h \
    EventFilterBase.h \
    DefaultEventFilter.h \
    EventRegisterBase.h \
    DefaultEventRegister.h \
    RegisterProvider.h \
    TreatmentEvent.h \
    PatientToHCWColonizationEvent.h \
    HCWToPatientColonizationEvent.h \
    DischargeEvent.h \
    Variable.h \
    Properties.h \
    InfectionProcessBase.h \
    ConstantProbabilityInfectionProcess.h \
    InfectionEvent.h \
    SimulationFactory.h \
    TestSimulationFactory.h \
    Experiment.h \
    ExperimentFixtureBase.h \
    TestExperimentFixture.h \
    OneWardColonizationModelFixture.h \
    OneWardColonizationSimulationFactory.h \
    GammaDistrSampler.h \
    WeibullDistrSampler.h \
    LognormalDistrSampler.h \
    TreatmentUgrencyStep.h \
    HCWDecolonizationProcess.h \
    PeriodicallyDecolonizationProcess.h \
    PeriodicallyHCWDecolonizationEvent.h \
    InitPatientEvent.h \
    InitHCWEvent.h

INCLUDEPATH += /usr/local/lib
DEPENDPATH += /usr/local/lib


LIBS  += -L"/usr/local/lib" -lboost_log -lboost_log_setup -lboost_system -lboost_thread -lpthread

