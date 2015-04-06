#include "testtypes.h"

#include <QMap>

namespace
{
    const QMap<Test::TestType, QString> cs_Types = {{Test::TestType::Invalid, TESTTYPE_INVALID},
                                                    {Test::TestType::Object, TESTTYPE_OBJECT},
                                                    {Test::TestType::Widget, TESTTYPE_WIDGET},
                                                    {Test::TestType::QML, TESTTYPE_QML}};

    const QMap<Test::TestLevel, QString> cs_Levels = {{Test::TestLevel::Invalid, TESTLEVEL_INVALID},
                                                     {Test::TestLevel::Unit, TESTLEVEL_UNIT},
                                                     {Test::TestLevel::Interaction, TESTLEVEL_INTERACTION},
                                                     {Test::TestLevel::Module, TESTLEVEL_MODULE},
                                                     {Test::TestLevel::System, TESTLEVEL_SYSTEM}};
}

QString Test::toString( Test::TestType type )
{
    return cs_Types.value( type, "Invalid" );
}

QString Test::toString( Test::TestLevel level )
{
    return cs_Levels.value( level, "Invalid" );
}

Test::TestType Test::toType( const QString &text )
{
    return cs_Types.key( text, Test::TestType::Invalid );
}

Test::TestLevel Test::toLevel( const QString &text )
{
    return cs_Levels.key( text, Test::TestLevel::Invalid );
}
