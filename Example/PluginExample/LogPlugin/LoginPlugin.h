#ifndef LOGINPLUGIN_H
#define LOGINPLUGIN_H

#include <ctkPluginActivator.h>

class LogQDebug;

class LoginPlugin :  public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)

#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
    Q_PLUGIN_METADATA(IID "LoginPlugin")
#endif

public:
    LoginPlugin();

    virtual void start(ctkPluginContext* pContent);
    virtual void stop(ctkPluginContext* pContent);

private:
    LogQDebug*  m_pLogService;
};

#endif // LOGINPLUGIN_H
