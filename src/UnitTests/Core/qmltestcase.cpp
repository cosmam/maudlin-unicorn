#include "qmltestcase.h"
#include "Private/qmltestcase_p.h"

#include "initparams.h"

using Test::InitParams;
using Test::QmlTestCase;
using Test::QmlTestCasePrivate;

namespace
{
    const QString cs_FilenameKey("QmlTestCase_Filename");
}

QmlTestCase::QmlTestCase( const InitParams &params, QObject *parent )
  : Test::TestCase(*(new QmlTestCasePrivate(this, params)), parent)
{
}

QmlTestCase::~QmlTestCase()
{
}

QString QmlTestCase::filename() const
{
    Q_D(const QmlTestCase);
    return d->m_filename;
}

void QmlTestCase::setFilename(const QString &filename)
{
    Q_D(QmlTestCase);
    d->m_filename = filename;
}

/************* Private Class Implementation *************/

QmlTestCasePrivate::QmlTestCasePrivate( QmlTestCase *parent, const InitParams &params )
  : Test::TestCasePrivate(parent, params)
{
    m_filename = Test::getValue<QString>(params, cs_FilenameKey);
}

QmlTestCasePrivate::~QmlTestCasePrivate()
{
}
