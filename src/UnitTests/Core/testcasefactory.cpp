#include "testcasefactory.h"
#include "testcase.h"
#include "initparams.h"

#include <QDebug>
#include <QMetaClassInfo>
#include <QMetaObject>

#include <map>
#include <mutex>

using Test::TestCaseFactory;
using Test::TestCase;
using Test::InitParams;

namespace
{
    struct TestConfig
    {
        QString module;
        Test::TestType type;
        Test::TestLevel level;

        TestConfig() : type(Test::TestType::Invalid), level(Test::TestLevel::Invalid) {}
    };

    TestConfig getTestConfig(const QMetaObject & metaObject);
}

class Test::TestCaseFactory::Impl
{
public:
    std::mutex registerMutex;
    std::map<QString, TestCaseFactory::CreateCallback> callbacks;
    std::map<QString, TestConfig> config;
};

TestCaseFactory &TestCaseFactory::getInstance()
{
    static TestCaseFactory factory;
    return factory;
}

TestCaseFactory::TestCaseFactory() : m_Impl( new Test::TestCaseFactory::Impl )
{
}

std::unique_ptr<Test::TestCase> TestCaseFactory::createTestCase( const QString &name ) const
{
    return createTestCase(name, InitParams());
}

std::unique_ptr<Test::TestCase> TestCaseFactory::createTestCase( const QString &name, const InitParams & data ) const
{
    auto it = m_Impl->callbacks.find( name );
    return ( it == m_Impl->callbacks.end() ? nullptr : ( it->second )( data ) );
}

void TestCaseFactory::registerTestCase(const QMetaObject & metaObject,
                                        TestCaseFactory::CreateCallback cb )
{
    auto config = getTestConfig(metaObject);
    std::lock_guard<std::mutex> lock( m_Impl->registerMutex );
    m_Impl->callbacks[metaObject.className()] = cb;
    m_Impl->config[metaObject.className()] = config;
}

std::vector<QString> TestCaseFactory::testCaseList() const
{
    std::vector<QString> keys;
    for( auto && entry : m_Impl->callbacks ) {
        keys.push_back( entry.first );
    }

    return keys;
}

namespace
{
    TestConfig getTestConfig(const QMetaObject & metaObject)
    {
        TestConfig config;

        qDebug() << "Registering Test:";
        qDebug() << "\tName:  " << metaObject.className();
        for( int i=0 ; i < metaObject.classInfoCount() ; ++i )
        {
            auto info = metaObject.classInfo(i);
            QString name = QString(info.name());
            if( name == TESTTYPE_KEY ) {
                config.type = Test::toType( info.value() );
                qDebug() << "\tType:  " << info.value();
            } else if( name == TESTLEVEL_KEY ) {
                config.level = Test::toLevel( info.value() );
                qDebug() << "\tLevel: " << info.value();
            } else if( name == TESTMODULE_KEY ) {
                config.module = info.value();
                qDebug() << "\tModule:" << info.value();
            }
        }

        return config;
    }
}
