#include "testrunconfig.h"

#include <map>

using Test::TestRunConfig;
using std::map;

class Test::TestRunConfig::Impl
{
public:
    std::vector<QString> keys;
    std::map<QString, Test::InitParams> params;
};

TestRunConfig::TestRunConfig() : m_Impl( new Test::TestRunConfig::Impl )
{
}

TestRunConfig::~TestRunConfig()
{
}

TestRunConfig::TestRunConfig( const TestRunConfig &rhs )
    : m_Impl( new Test::TestRunConfig::Impl( *rhs.m_Impl ) )
{
}

TestRunConfig &TestRunConfig::operator=( const TestRunConfig &rhs )
{
    *m_Impl = *rhs.m_Impl;
    return *this;
}

TestRunConfig::TestRunConfig( TestRunConfig &&rhs ) : m_Impl( std::move( rhs.m_Impl ) )
{
}

TestRunConfig &TestRunConfig::operator=( TestRunConfig &&rhs )
{
    m_Impl = std::move( rhs.m_Impl );
    return *this;
}

void TestRunConfig::addTestCase(const QString &name, Test::InitParams params)
{
    m_Impl->keys.push_back(name);
    m_Impl->params[name] = params;
}

std::vector<QString> TestRunConfig::testCaseList() const
{
    return m_Impl->keys;
}

Test::InitParams TestRunConfig::getParams(const QString &name) const
{
    auto it = m_Impl->params.find( name );
    return ( it == m_Impl->params.end() ? Test::InitParams() : it->second );

}

