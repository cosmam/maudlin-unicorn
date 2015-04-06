TEMPLATE = app

QT += qml quick widgets testlib

CONFIG += c++11

INCLUDEPATH += src/

SOURCES += main.cpp \
    src/UnitTests/Core/testcasefactory.cpp \
    src/UnitTests/Core/testcase.cpp \
    src/UnitTests/Core/initparams.cpp \
    src/UnitTests/Core/qmltestcase.cpp \
    src/UnitTests/Core/testtypes.cpp \
    src/UnitTests/Core/testcaseattributes.cpp \
    src/UnitTests/Core/testresult.cpp \
    src/UnitTests/Runner/testcaserunner.cpp \
    src/UnitTests/Runner/testconfigloader.cpp \
    src/UnitTests/Runner/testrunconfig.cpp

HEADERS += \
    src/UnitTests/Core/testcase.h \
    src/UnitTests/Core/testtypes.h \
    src/UnitTests/Core/testcasefactory.h \
    src/UnitTests/Core/Private/testcase_p.h \
    src/UnitTests/Core/initparams.h \
    src/UnitTests/Core/qmltestcase.h \
    src/UnitTests/Core/Private/qmltestcase_p.h \
    src/UnitTests/Core/testcaseattributes.h \
    src/UnitTests/Core/testresult.h \
    src/UnitTests/Runner/testcaserunner.h \
    src/UnitTests/Runner/Private/testcaserunner_p.h \
    src/UnitTests/Runner/testconfigloader.h \
    src/UnitTests/Runner/Private/testconfigloader_p.h \
    src/UnitTests/Runner/testrunconfig.h

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
