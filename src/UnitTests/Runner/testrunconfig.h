#ifndef TESTRUNCONFIG_T_H
#define TESTRUNCONFIG_T_H

#include "UnitTests/Core/initparams.h"

#include <memory>
#include <vector>

namespace Test
{

    class TestRunConfig
    {
    public:
        TestRunConfig();

        ~TestRunConfig();

        TestRunConfig( const TestRunConfig &rhs );
        TestRunConfig &operator=( const TestRunConfig &rhs );

        TestRunConfig( TestRunConfig &&rhs );
        TestRunConfig &operator=( TestRunConfig &&rhs );

        void addTestCase(const QString & name, Test::InitParams params);

        std::vector<QString> testCaseList() const;

        Test::InitParams getParams(const QString & name) const;

    private:
        class Impl;
        std::unique_ptr<Impl> m_Impl;
    };
}

#endif // TESTRUNCONFIG_T_H
