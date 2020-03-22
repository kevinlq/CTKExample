#include "LoginPlugin.h"

#include "LogQDebug.h"


LoginPlugin::LoginPlugin()
    : m_pLogService(Q_NULLPTR)
{
}

void LoginPlugin::start(ctkPluginContext *pContent)
{
    if (m_pLogService == Q_NULLPTR)
    {
        m_pLogService = new(std::nothrow) LogQDebug();
    }

    pContent->registerService(QStringList("ctkLogService"), m_pLogService);
}

void LoginPlugin::stop(ctkPluginContext *pContent)
{
    Q_UNUSED(pContent);

    if (m_pLogService != Q_NULLPTR)
    {
        delete m_pLogService;
        m_pLogService = Q_NULLPTR;
    }
}


#if (QT_VERSION < QT_VERSION_CHECK(5,0,0))
Q_EXPORT_PLUGIN2(org_commontk_log, LoginPlugin)
#endif
