#include "HelloImpl.h"

#include "ctkPluginContext.h"

#include <QDebug>

HelloImpl::HelloImpl(ctkPluginContext *pContent)
{
    pContent->registerService<HelloServer>(this);
}

void HelloImpl::sayHello()
{
    qDebug () << "say hello!" <<endl;
}
