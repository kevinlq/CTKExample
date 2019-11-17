#ifndef WELCOMEQTACTIVATOR_H
#define WELCOMEQTACTIVATOR_H

#include <ctkPluginActivator.h>

#include <QObject>

class WelcomeQtImpl;

class WelcomeQtActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
        Q_PLUGIN_METADATA(IID "WELCOME_QT")
public:
    WelcomeQtActivator();
    ~WelcomeQtActivator();

    virtual void start(ctkPluginContext *pContent);
    virtual void stop(ctkPluginContext *pContent);

private:
    WelcomeQtImpl *m_pImpl;
};

#endif // WELCOMEQTACTIVATOR_H
