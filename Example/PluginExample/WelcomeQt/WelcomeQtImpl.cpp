#include "WelcomeQtImpl.h"

#include <QDebug>

WelcomeQtImpl::WelcomeQtImpl()
{
}

WelcomeQtImpl::~WelcomeQtImpl()
{
}

void WelcomeQtImpl::welcome()
{
    qDebug () << " welcome Qt!";
}
