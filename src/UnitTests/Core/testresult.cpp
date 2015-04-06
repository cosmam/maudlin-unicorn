#include "testresult.h"

using Test::TestResult;

class Test::TestResult::Impl
{
public:
    Impl(bool inPassed, QString inError) : passed( inPassed ), error(inError) {}

    bool passed;
    QString error;
};

TestResult::TestResult(bool passed, QString error) : m_Impl( new Test::TestResult::Impl(passed, error) )
{
}

TestResult::~TestResult()
{
}

TestResult::TestResult( const TestResult &rhs )
    : m_Impl( new Test::TestResult::Impl( *rhs.m_Impl ) )
{
}

TestResult &TestResult::operator=( const TestResult &rhs )
{
    *m_Impl = *rhs.m_Impl;
    return *this;
}

TestResult::TestResult( TestResult &&rhs ) : m_Impl( std::move( rhs.m_Impl ) )
{
}

TestResult &TestResult::operator=( TestResult &&rhs )
{
    m_Impl = std::move( rhs.m_Impl );
    return *this;
}

bool TestResult::passed() const
{
    return m_Impl->passed;
}

QString TestResult::error() const
{
    return m_Impl->error;
}

void TestResult::setPassed( bool passed )
{
    m_Impl->passed = passed;
}

void TestResult::setError( const QString &error )
{
    m_Impl->error = error;
}
