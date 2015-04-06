#ifndef TESTCONFIGLOADER_T_H
#define TESTCONFIGLOADER_T_H

#include "testrunconfig.h"

#include <QObject>

namespace Test
{
    class TestConfigLoaderPrivate;

    class TestConfigLoader : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE( Test::TestConfigLoader )
        Q_DISABLE_COPY( TestConfigLoader )

    public:

        explicit TestConfigLoader( QObject *parent = 0 );

        ~TestConfigLoader();

        Test::TestRunConfig loadTestRun(const QString & runName);

    signals:

    public slots:

    private:
        QScopedPointer<TestConfigLoaderPrivate> d_ptr;
    };
}
#endif // TESTCONFIGLOADER_T_H
