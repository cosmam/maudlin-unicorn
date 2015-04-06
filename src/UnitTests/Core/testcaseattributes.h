#ifndef TESTCASEATTRIBUTES_T_H
#define TESTCASEATTRIBUTES_T_H

#include "testtypes.h"

#include <memory>

class QObject;

namespace Test
{
    class TestCaseAttributes
    {
    public:
        TestCaseAttributes( QObject *testCase );

        ~TestCaseAttributes();

        bool isValid() const;

        QString name() const;

        TestCaseAttributes &setName( const QString &name );

        QString module() const;

        TestCaseAttributes &setModule( const QString &module );

        Test::TestLevel level() const;

        TestCaseAttributes &setLevel( Test::TestLevel level );

        Test::TestType type() const;

        TestCaseAttributes &setType( Test::TestType type );

    private:
        class Impl;
        std::unique_ptr<Impl> m_Impl;
    };
}

#endif // TESTCASEATTRIBUTES_T_H
