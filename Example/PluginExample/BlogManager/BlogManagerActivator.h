#ifndef BLOGMANAGERACTIVATOR_H
#define BLOGMANAGERACTIVATOR_H

#include <QObject>

#include <ctkPluginActivator.h>

class BlogManager;

class BlogManagerActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "BLOG_MANAGER")

public:
    explicit BlogManagerActivator();

    virtual void start(ctkPluginContext *pContent);
    virtual void stop(ctkPluginContext *pContent);

private:
    BlogManager *m_pBlogManager;
};

#endif // BLOGMANAGERACTIVATOR_H
