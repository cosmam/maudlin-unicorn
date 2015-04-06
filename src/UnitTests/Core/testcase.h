#ifndef TESTCASE_T_H
#define TESTCASE_T_H

#include "testresult.h"
#include "testtypes.h"

#include <QObject>

class QTestData;

namespace Test
{
    class InitParams;
    class TestCasePrivate;

    class TestCase : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE( Test::TestCase )
        Q_DISABLE_COPY( TestCase )

    public:
        TestCase( const InitParams & params, QObject *parent = nullptr );

        virtual ~TestCase();

        virtual bool isValid() const;

        virtual Test::TestResult runTests();

    protected:

        size_t runCount() const;

        void setRunCount(size_t runCount);

        /// Allows for adding new test row data by int
        QTestData &newRow( int rowNum );

        /// Allows for adding new test row data by QString
        QTestData &newRow( const QString &text );

        /// Allows for adding new test row data by const char *
        QTestData &newRow( const char *text );

        explicit TestCase(TestCasePrivate & d, QObject * parent = nullptr);
        QScopedPointer<TestCasePrivate> d_ptr;
    };

    Test::TestLevel getLevel(const QMetaObject & metaObject);

    Test::TestType getType(const QMetaObject & metaObject);

    QString getModule(const QMetaObject & metaObject);
}

#define TESTMODULE_KEY TO_STRING(TestModule_Key)
#define TESTLEVEL_KEY TO_STRING(TestLevel_Key)
#define TESTTYPE_KEY TO_STRING(TestType_Key)

#endif // TESTCASE_T_H
