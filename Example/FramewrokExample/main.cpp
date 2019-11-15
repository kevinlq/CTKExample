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

#include "./../PluginExample/HelloPlugin/HelloServer.h"

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

            // 获取清单头和值
            QHash<QString, QString> headers = plugin->getHeaders();
            qDebug() << "Headers:" << headers << "\r\n";

            // 获取符号名
            QString symb = plugin->getSymbolicName();
            qDebug() << "Symbolic Name:" << symb << "\r\n";

            // 获取版本号
            ctkVersion version = plugin->getVersion();
            qDebug() << "Version:" << version.toString()
                     << "Major:" << version.getMajor()
                     << "Micro:" << version.getMicro()
                     << "Minor:" << version.getMinor()
                     << "Qualifier:" << version.getQualifier();

            plugin->start(ctkPlugin::START_TRANSIENT);
            qDebug () << "start plug "<< strPlugin;

        } catch (ctkPluginException &e) {
            qDebug () <<"failed install plugin " << strPlugin << e.what();
            return -1;
        }
    }

    // 获取服务引用
    ctkServiceReference reference = pContent->getServiceReference<HelloServer>();
    if (reference)
    {
        HelloServer *pServer = qobject_cast<HelloServer*>(pContent->getService(reference));

        if (pServer != Q_NULLPTR)
        {
            pServer->sayHello();
        }
    }

    return a.exec();
}
