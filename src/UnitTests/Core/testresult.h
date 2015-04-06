#ifndef TESTRESULT_T_H
#define TESTRESULT_T_H

#include <QString>
#include <memory>

namespace Test
{
    class TestResult
    {
    public:
        TestResult(bool passed = false, QString error = "");

        ~TestResult();

        TestResult( const TestResult &rhs );
        TestResult &operator=( const TestResult &rhs );

        TestResult( TestResult &&rhs );
        TestResult &operator=( TestResult &&rhs );

        bool passed() const;

        QString error() const;

        void setPassed(bool passed);

        void setError(const QString & error);

    private:
        class Impl;
        std::unique_ptr<Impl> m_Impl;
    };
}

#endif // TESTRESULT_T_H
