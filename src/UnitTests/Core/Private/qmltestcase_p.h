#ifndef QMLTESTCASEPRIVATE_T_H
#define QMLTESTCASEPRIVATE_T_H

#include "../qmltestcase.h"
#include "testcase_p.h"

#include <QObject>

namespace Test
{
    class InitParams;
    class QmlTestCase;

    class QmlTestCasePrivate : public TestCasePrivate
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC( Test::QmlTestCase )
        Q_DISABLE_COPY( QmlTestCasePrivate )

    public:

        QmlTestCasePrivate( Test::QmlTestCase * parent, const InitParams & params );

        virtual ~QmlTestCasePrivate();

        QString m_filename;
    };
}
#endif // QMLTESTCASEPRIVATE_T_H
