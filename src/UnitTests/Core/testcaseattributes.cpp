#include "testcaseattributes.h"

#include <QObject>

using Test::TestCaseAttributes;

class Test::TestCaseAttributes::Impl
{
public:

    Impl(const char * className) : name(className) {}

    QString name;
    QString  module;
    Test::TestLevel level;
    Test::TestType type;
};

TestCaseAttributes::TestCaseAttributes( QObject *testCase )
  : m_Impl(new Test::TestCaseAttributes::Impl(testCase->metaObject()->className()))
{

}

TestCaseAttributes::~TestCaseAttributes()
{

}

bool TestCaseAttributes::isValid() const
{
    return (!m_Impl->name.isEmpty() && m_Impl->module.isEmpty() &&
            m_Impl->level != Test::TestLevel::Invalid &&
            m_Impl->type != Test::TestType::Invalid );
}

QString TestCaseAttributes::name() const
{
    return m_Impl->name;
}

TestCaseAttributes &TestCaseAttributes::setName( const QString &name )
{
    m_Impl->name = name;
    return *this;
}

QString TestCaseAttributes::module() const
{
    return m_Impl->module;
}

TestCaseAttributes &TestCaseAttributes::setModule( const QString &module )
{
    m_Impl->module = module;
    return *this;
}

Test::TestLevel TestCaseAttributes::level() const
{
    return m_Impl->level;
}

TestCaseAttributes &TestCaseAttributes::setLevel( Test::TestLevel level )
{
    m_Impl->level = level;
    return *this;
}

Test::TestType TestCaseAttributes::type() const
{
    return m_Impl->type;
}

TestCaseAttributes &TestCaseAttributes::setType( Test::TestType type )
{
    m_Impl->type = type;
    return *this;
}

