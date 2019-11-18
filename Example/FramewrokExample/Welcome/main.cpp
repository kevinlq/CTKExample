// Qt lib
#include <QCoreApplication>
#include <QDebug>
#include <QSharedPointer>
#include <QDirIterator>

// CTK lib
#include "ctkPluginFrameworkFactory.h"
#include "ctkPluginFramework.h"
#include "ctkPluginContext.h"
#include "ctkPluginException.h"

#include "ctkServiceReference.h"

#include "./../../PluginExample/WelcomeCTK/WelcomeService.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ctkPluginFrameworkFactory factory;
    QSharedPointer<ctkPluginFramework> framework = factory.getFramework();

    try {
        framework->init();
        framework->start();
    } catch (ctkPluginException &e)
    {
        qDebug() << "failed init ctk pluginframework " << e.what();
        return -1;
    }

    // 插件上下文
    ctkPluginContext *pContent = framework->getPluginContext();
    QString strPath = QCoreApplication::applicationDirPath() + "/plugins";

    QStringList lsFilters;
    lsFilters << "*.dll" << "*.so";
    QDirIterator iterPlugin(strPath, lsFilters, QDir::Files);

    // 遍历安装
    while (iterPlugin.hasNext())
    {
        QString strPlugin = iterPlugin.next();
        if (strPlugin.isEmpty())
        {
            continue;
        }

        try {
            QSharedPointer<ctkPlugin> plugin = pContent->installPlugin(QUrl::fromLocalFile(strPlugin));

            if (Q_NULLPTR == plugin)
            {
                continue;
            }

            plugin->start(ctkPlugin::START_TRANSIENT);
            qDebug () << "start plug "<< strPlugin;

        } catch (ctkPluginException &e) {
            qDebug () <<"failed install plugin " << strPlugin << e.what();
            return -1;
        }
    }

    // 1. 获取所有服务
    QList<ctkServiceReference> refs = pContent->getServiceReferences<WelcomeService>();

    foreach (ctkServiceReference ref, refs)
    {
        qDebug () <<" name:" << ref.getProperty ("name").toString ()
                 << "service ranking:" << ref.getProperty (ctkPluginConstants::SERVICE_RANKING).toLongLong ()
                 << "service id:" << ref.getProperty (ctkPluginConstants::SERVICE_ID).toLongLong ();

        WelcomeService *pService = qobject_cast<WelcomeService*>(pContent->getService (ref));

        if (Q_NULLPTR != pService)
        {
            pService->welcome ();
        }
    }

    qDebug () <<" welcom =================================";

    // 2. 使用过滤表达式，获取感兴趣服务
    refs = pContent->getServiceReferences<WelcomeService>("(&(name=CTK))");
    foreach (ctkServiceReference ref, refs)
    {
        if (ref)
        {
            WelcomeService *pService = qobject_cast<WelcomeService*>(pContent->getService (ref));

            if (Q_NULLPTR != pService)
            {
                pService->welcome ();
            }
        }
    }


    // 3. 获取某一个服务,根据属性
    ctkServiceReference ref = pContent->getServiceReference<WelcomeService>();
    if (ref)
    {
        WelcomeService *pService = qobject_cast<WelcomeService*>(pContent->getService (ref));

        if (Q_NULLPTR != pService)
        {
            pService->welcome ();
        }
    }

    return a.exec();
}
