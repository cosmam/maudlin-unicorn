#include "testcase.h"
#include "Private/testcase_p.h"

#include "initparams.h"

#include <QMetaClassInfo>
#include <QtTest>

using Test::InitParams;
using Test::TestCase;
using Test::TestCasePrivate;

namespace
{
    const size_t cs_RunCountDefault(20);
    const QString cs_RunCountKey("TestCase_RunCount");
}

TestCase::TestCase( const InitParams &params, QObject *parent )
    : QObject( parent ), d_ptr( new TestCasePrivate( this, params ) )
{
}

TestCase::TestCase(Test::TestCasePrivate &d, QObject *parent)
  : QObject(parent), d_ptr(&d)
{

}

TestCase::~TestCase()
{
}

bool TestCase::isValid() const
{
    return true;
}

Test::TestResult TestCase::runTests()
{
    auto success = isValid() ? QTest::qExec( this ) : -1;
    return Test::TestResult(success == 0);
}

size_t TestCase::runCount() const
{
    Q_D(const TestCase);
    return d->m_runCount;
}

void TestCase::setRunCount(size_t runCount)
{
    Q_D(TestCase);
    d->m_runCount = runCount;
}

QTestData &TestCase::newRow(int rowNum)
{
    return QTest::newRow( qPrintable( QString::number( rowNum ) ) );
}

QTestData &TestCase::newRow(const QString &text)
{
    return QTest::newRow( qPrintable( text ) );
}

QTestData &TestCase::newRow(const char *text)
{
    return QTest::newRow( text );
}

/************* Private Class Implementation *************/

TestCasePrivate::TestCasePrivate( TestCase *parent, const InitParams & params )
  : QObject( parent ), q_ptr( parent )
{
    m_runCount = Test::getValue<size_t>(params, cs_RunCountKey, cs_RunCountDefault);
}

TestCasePrivate::~TestCasePrivate()
{
}


Test::TestLevel Test::getLevel(const QMetaObject &metaObject)
{
    return Test::toLevel( metaObject.classInfo( metaObject.indexOfClassInfo(TESTLEVEL_KEY) ).value() );
}


Test::TestType Test::getType(const QMetaObject &metaObject)
{
    return Test::toType( metaObject.classInfo( metaObject.indexOfClassInfo(TESTTYPE_KEY) ).value() );
}


QString Test::getModule(const QMetaObject &metaObject)
{
    return QString( metaObject.classInfo( metaObject.indexOfClassInfo(TESTMODULE_KEY) ).value() );
}
