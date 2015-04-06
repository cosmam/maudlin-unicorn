#include "testcaserunner.h"
#include "Private/testcaserunner_p.h"
#include "testconfigloader.h"

#include "UnitTests/Core/testcase.h"
#include "UnitTests/Core/testcasefactory.h"

using Test::TestCaseRunner;
using Test::TestCaseRunnerPrivate;

TestCaseRunner::TestCaseRunner(QObject *parent) : QObject(parent), d_ptr(new Test::TestCaseRunnerPrivate(this))
{

}

TestCaseRunner::~TestCaseRunner()
{

}

void TestCaseRunner::runTests()
{
    Q_D(TestCaseRunner);
    auto runConfig = d->m_configLoader->loadTestRun("");
    for( auto && testName : runConfig.testCaseList() )
    {
        auto testCase = d->m_factory.createTestCase(testName, runConfig.getParams(testName));
        if( testCase != nullptr ) {
            auto result = testCase->runTests();
        }
    }
}

/************* Private class implementation *************/

TestCaseRunnerPrivate::TestCaseRunnerPrivate(Test::TestCaseRunner *parent)
  : QObject(parent), q_ptr(parent), m_factory(Test::TestCaseFactory::getInstance()),
    m_configLoader(new Test::TestConfigLoader)
{

}

TestCaseRunnerPrivate::~TestCaseRunnerPrivate()
{

}
