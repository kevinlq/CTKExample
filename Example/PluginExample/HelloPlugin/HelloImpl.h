#ifndef HELLOIMPL_H
#define HELLOIMPL_H

#include "HelloServer.h"

#include <QtCore/QObject>

class ctkPluginContext;

class HelloImpl : public QObject, public HelloServer
{
    Q_OBJECT
    Q_INTERFACES(HelloServer)
public:
    explicit HelloImpl(ctkPluginContext *pContent);

    virtual void sayHello();
};

#endif // HELLOIMPL_H
