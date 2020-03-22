#ifndef WELCOMECTKACTIVATOR_H
#define WELCOMECTKACTIVATOR_H

#include <ctkPluginActivator.h>

#include <QObject>

class WelcomeCTKImpl;

class WelcomeCTKActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0) )
    Q_PLUGIN_METADATA(IID "WELCOME_CTK")
#endif

public:
    WelcomeCTKActivator();
    ~WelcomeCTKActivator();

    virtual void start(ctkPluginContext *pContent);
    virtual void stop(ctkPluginContext *pContent);

private:
    WelcomeCTKImpl *m_pImpl;
};

#endif // WELCOMECTKACTIVATOR_H
