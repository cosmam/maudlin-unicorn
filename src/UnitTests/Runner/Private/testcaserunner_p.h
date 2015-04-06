#ifndef TESTCASERUNNER_P_T_H
#define TESTCASERUNNER_P_T_H

#include <QObject>

namespace Test
{
    class TestCaseFactory;
    class TestCaseRunner;
    class TestConfigLoader;

    class TestCaseRunnerPrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC( Test::TestCaseRunner )
        Q_DISABLE_COPY( TestCaseRunnerPrivate )

    public:
        explicit TestCaseRunnerPrivate( Test::TestCaseRunner *parent );

        ~TestCaseRunnerPrivate();

        Test::TestCaseRunner * q_ptr;

        const Test::TestCaseFactory & m_factory;

        QScopedPointer<Test::TestConfigLoader> m_configLoader;

    signals:

    public slots:

    };
}

#endif // TESTCASERUNNER_P_T_H
