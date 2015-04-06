#ifndef TESTCASEPRIVATE_T_H
#define TESTCASEPRIVATE_T_H

#include "../testtypes.h"

#include <QObject>

namespace Test
{
    class InitParams;
    class TestCase;

    class TestCasePrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC( Test::TestCase )
        Q_DISABLE_COPY( TestCasePrivate )

    public:
        TestCasePrivate( Test::TestCase *parent, const InitParams & params );

        virtual ~TestCasePrivate();

        Test::TestCase *q_ptr;

        size_t m_runCount;
    };
}

#endif // TESTCASEPRIVATE_TI_H
