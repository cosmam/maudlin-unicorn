#ifndef TESTCASERUNNER_T_H
#define TESTCASERUNNER_T_H

#include <QObject>

namespace Test
{
    class TestCaseRunnerPrivate;

    class TestCaseRunner : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE( Test::TestCaseRunner )
        Q_DISABLE_COPY( TestCaseRunner )

    public:
        explicit TestCaseRunner( QObject *parent = nullptr );

        ~TestCaseRunner();

        void runTests();

    signals:

    public slots:

    private:
        QScopedPointer<TestCaseRunnerPrivate> d_ptr;
    };
}

#endif // TESTCASERUNNER_T_H
