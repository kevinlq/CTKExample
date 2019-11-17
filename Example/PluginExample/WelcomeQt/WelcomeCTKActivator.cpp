#include "WelcomeCTKActivator.h"

#include "WelcomeCTKImpl.h"

// ctk lib
#include "ctkPluginFramework_global.h"

// Qt lib
#include <QVariant>
#include <QHash>
#include <QDebug>

WelcomeCTKActivator::WelcomeCTKActivator()
    :m_pImpl(Q_NULLPTR)
{
}

WelcomeCTKActivator::~WelcomeCTKActivator()
{
    if (Q_NULLPTR != m_pImpl)
    {
        delete m_pImpl;
        m_pImpl = Q_NULLPTR;
    }
}

void WelcomeCTKActivator::start(ctkPluginContext *pContent)
{
    if (Q_NULLPTR == pContent)
    {
        qWarning () << "pContent is NULL";
        return;
    }

    if ( Q_NULLPTR == m_pImpl)
    {
        m_pImpl = new WelcomeCTKImpl();
    }

    ctkDictionary property;
    property.insert (ctkPluginConstants::SERVICE_RANKING, 2);
    property.insert ("name", "CTK");

    //pContent->registerService <WelcomeService>(m_pServer, property);
    pContent->registerService<WelcomeService>(m_pImpl, property);
}

void WelcomeCTKActivator::stop(ctkPluginContext *pContent)
{
    Q_UNUSED(pContent);
}
