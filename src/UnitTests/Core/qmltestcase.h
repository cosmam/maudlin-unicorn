#ifndef QMLTESTCASE_T_H
#define QMLTESTCASE_T_H

#include "testcase.h"

#include <QObject>

namespace Test
{
    class InitParams;
    class QmlTestCasePrivate;

    class QmlTestCase : public Test::TestCase
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE( Test::QmlTestCase )
        Q_DISABLE_COPY( QmlTestCase )
        Q_PROPERTY( QString filename READ filename WRITE setFilename )

    public:

        QmlTestCase( const InitParams & params, QObject * parent = nullptr );

        virtual ~QmlTestCase();

        QString filename() const;

    public slots:

        void setFilename(const QString & filename);

    };
}

#endif // QMLTESTCASE_T_H
