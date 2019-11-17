#ifndef WELCOMECTKIMPL_H
#define WELCOMECTKIMPL_H

#include <QtCore/QObject>

#include "WelcomeService.h"

class WelcomeCTKImpl : public QObject,  public WelcomeService
{
    Q_OBJECT
    Q_INTERFACES(WelcomeService)
public:
    WelcomeCTKImpl();
    ~WelcomeCTKImpl();

    virtual void welcome () Q_DECL_OVERRIDE;
};

#endif // WELCOMECTKIMPL_H
