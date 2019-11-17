#ifndef WELCOMESERVICE_H
#define WELCOMESERVICE_H

#include <QtPlugin>

class WelcomeService
{
public:
    WelcomeService();
    virtual ~WelcomeService();

    virtual void welcome() = 0;
};

#define WelcomeService_iid "org.commontk.service.demos.WelcomeService"
Q_DECLARE_INTERFACE(WelcomeService, WelcomeService_iid)

#endif // WELCOMESERVICE_H
