#include "HelloActivator.h"
#include "HelloImpl.h"

#include <QDebug>

HelloActivator::HelloActivator()
{
}

HelloActivator::~HelloActivator()
{
    qDebug () <<"~HelloActivator";
}

void HelloActivator::start(ctkPluginContext *pContent)
{
    s.reset(new HelloImpl(pContent));
}

void HelloActivator::stop(ctkPluginContext *pContent)
{
    Q_UNUSED(pContent);

    qDebug () << " activator stop ";
}
