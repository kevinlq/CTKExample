#include "WelcomeQtActivator.h"

#include "WelcomeQtImpl.h"

// ctk lib
#include "ctkPluginFramework_global.h"

// Qt lib
#include <QVariant>
#include <QHash>
#include <QDebug>

WelcomeQtActivator::WelcomeQtActivator()
    :m_pImpl(Q_NULLPTR)
{

}

WelcomeQtActivator::~WelcomeQtActivator()
{
    if (Q_NULLPTR != m_pImpl)
    {
        delete m_pImpl;
        m_pImpl = Q_NULLPTR;
    }
}

void WelcomeQtActivator::start(ctkPluginContext *pContent)
{
    if (Q_NULLPTR == pContent)
    {
        qWarning () << "pContent is NULL";
        return;
    }

    if ( Q_NULLPTR == m_pImpl)
    {
        m_pImpl = new WelcomeQtImpl();
    }

    ctkDictionary property;
    property.insert (ctkPluginConstants::SERVICE_RANKING, 1);
    property.insert ("name", "Qt");

    pContent->registerService<WelcomeService>(m_pImpl, property);
}

void WelcomeQtActivator::stop(ctkPluginContext *pContent)
{
    Q_UNUSED(pContent);
}
