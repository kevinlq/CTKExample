#ifndef HELLOACTIVATOR_H
#define HELLOACTIVATOR_H

#include <ctkPluginActivator.h>
#include <QtCore/QObject>

#include "HelloServer.h"

class HelloActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID"HELLO_CTK")
public:
    HelloActivator();
    ~HelloActivator();

    virtual void start(ctkPluginContext *pContent);
    virtual void stop(ctkPluginContext *pContent);

private:
    QScopedPointer<HelloServer> s;
};

#endif // HELLOACTIVATOR_H
