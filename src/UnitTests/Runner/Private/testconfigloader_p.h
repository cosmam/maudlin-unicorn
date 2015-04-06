#ifndef TESTCONFIGLOADER_P_T_H
#define TESTCONFIGLOADER_P_T_H

#include "UnitTests/Core/initparams.h"

#include <QObject>

namespace Test
{
    class TestCaseFactory;
    class TestConfigLoader;

    class TestConfigLoaderPrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC( Test::TestConfigLoader )
        Q_DISABLE_COPY( TestConfigLoaderPrivate )

    public:
        explicit TestConfigLoaderPrivate( Test::TestConfigLoader * parent );

        ~TestConfigLoaderPrivate();

        Test::InitParams loadParams(const QString & runName, const QString & testName);

        Test::TestConfigLoader * q_ptr;

        const Test::TestCaseFactory & m_factory;

    signals:

    public slots:
    };
}

#endif // TESTCONFIGLOADER_P_T_H
