#include "testconfigloader.h"
#include "Private/testconfigloader_p.h"

#include "UnitTests/Core/testcasefactory.h"

using Test::TestConfigLoader;
using Test::TestConfigLoaderPrivate;

TestConfigLoader::TestConfigLoader( QObject *parent )
    : QObject( parent ), d_ptr( new Test::TestConfigLoaderPrivate( this ) )
{
}

TestConfigLoader::~TestConfigLoader()
{
}

Test::TestRunConfig TestConfigLoader::loadTestRun( const QString & runName )
{
    Q_D(TestConfigLoader);
    Test::TestRunConfig config;
    for( auto && testName : d->m_factory.testCaseList() ) {
        config.addTestCase(testName, d->loadParams(runName, testName));
    }

    return config;
}

/************* Private class implementation *************/

TestConfigLoaderPrivate::TestConfigLoaderPrivate( Test::TestConfigLoader *parent )
    : QObject( parent ), q_ptr( parent ), m_factory( Test::TestCaseFactory::getInstance() )
{
}

TestConfigLoaderPrivate::~TestConfigLoaderPrivate()
{
}

Test::InitParams TestConfigLoaderPrivate::loadParams(const QString &runName, const QString &testName)
{
    Q_UNUSED(runName);
    Q_UNUSED(testName);

    return Test::InitParams();
}
