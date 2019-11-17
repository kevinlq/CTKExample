#ifndef WELCOMEQTIMPL_H
#define WELCOMEQTIMPL_H

#include <QtCore/QObject>

#include "WelcomeService.h"

class WelcomeQtImpl : public QObject, public WelcomeService
{
    Q_OBJECT
    Q_INTERFACES(WelcomeService)
public:
    WelcomeQtImpl();
    ~WelcomeQtImpl();

    virtual void welcome ();
};

#endif // WELCOMEQTIMPL_H
