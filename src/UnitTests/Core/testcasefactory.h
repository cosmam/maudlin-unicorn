#ifndef TESTCASEFACTORY_T_H
#define TESTCASEFACTORY_T_H

#include <QString>

#include <memory>
#include <vector>

class QMetaObject;

namespace Test
{
    class TestCase;
    class InitParams;

    class TestCaseFactory
    {
    public:
        using CreateCallback = std::unique_ptr<Test::TestCase>( * )( const InitParams & );

        static TestCaseFactory &getInstance();

        std::unique_ptr<Test::TestCase> createTestCase( const QString &name ) const;

        std::unique_ptr<Test::TestCase> createTestCase( const QString &name,
                                                        const Test::InitParams &data ) const;

        void registerTestCase( const QMetaObject &metaObject, CreateCallback cb );

        std::vector<QString> testCaseList() const;

    private:
        TestCaseFactory();

        class Impl;
        std::unique_ptr<Impl> m_Impl;
    };
}

#define REGISTER_TESTCASE( metaObject, func )                                                      \
    bool registerTestCase()                                                                        \
    {                                                                                              \
        Test::TestCaseFactory::getInstance().registerTestCase( metaObject, func );                 \
        return true;                                                                               \
    }                                                                                              \
    bool registered = registerTestCase();

#endif // TESTCASEFACTORY_T_H
