#ifndef BLOGEVENTHANDLERACTIVATOR_H
#define BLOGEVENTHANDLERACTIVATOR_H


#include <QObject>

#include <ctkPluginActivator.h>

class BlogEventHandler;

class BlogEventHandlerActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "BLOG_EVENT_HANDLER")
public:
    BlogEventHandlerActivator();

public:
    virtual void start(ctkPluginContext *pContent);
    virtual void stop(ctkPluginContext *pContent);

private:
    BlogEventHandler *m_pEventHandler;
};

#endif // BLOGEVENTHANDLERACTIVATOR_H
