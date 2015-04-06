#ifndef TESTTYPES_T_H
#define TESTTYPES_T_H

#include <QMetaType>
#include <QString>

namespace Test
{
    enum class TestType { Invalid, Object, Widget, QML };

    enum class TestLevel { Invalid, Unit, Interaction, Module, System };

    QString toString(Test::TestType type);

    QString toString(Test::TestLevel level);

    Test::TestType toType(const QString & text);

    Test::TestLevel toLevel(const QString & text);
}

Q_DECLARE_METATYPE( Test::TestType )
Q_DECLARE_METATYPE( Test::TestLevel )

#define TO_STRING(macro) #macro
#define TESTTYPE_INVALID TO_STRING(Invalid)
#define TESTTYPE_OBJECT TO_STRING(Object)
#define TESTTYPE_WIDGET TO_STRING(Widget)
#define TESTTYPE_QML TO_STRING(Qml)
#define TESTLEVEL_INVALID TO_STRING(Invalid)
#define TESTLEVEL_UNIT TO_STRING(Unit)
#define TESTLEVEL_INTERACTION TO_STRING(Interaction)
#define TESTLEVEL_MODULE TO_STRING(Module)
#define TESTLEVEL_SYSTEM TO_STRING(System)

#endif // TESTTYPES_T_H
