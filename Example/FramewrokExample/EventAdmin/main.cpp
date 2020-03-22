// Qt lib
#include <QCoreApplication>
#include <QDebug>
#include <QSharedPointer>
#include <QDirIterator>

// CTK lib
#include "ctkPluginFrameworkLauncher.h"
#include "ctkPluginFrameworkFactory.h"
#include "ctkPluginFramework.h"
#include "ctkPluginContext.h"
#include "ctkPluginException.h"

#include "ctkServiceReference.h"

#include "./../../PluginExample/BlogEventHandler/BlogEventHandler.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString strPath = QCoreApplication::applicationDirPath () + "/plugins";

    // 添加到插件搜索路径中
    ctkPluginFrameworkLauncher::addSearchPath (strPath);

    // 设置并启动 CTK 插件框架
    ctkPluginFrameworkLauncher::start("org.commontk.eventadmin");

    // 获取插件上下文
    ctkPluginContext *pContext = ctkPluginFrameworkLauncher::getPluginContext();

    if (Q_NULLPTR == pContext)
    {
        qWarning () <<" error content is NULL";
    }

    // 启动插件 BlogEventHandler
    try {
        QString strPluginPath = strPath + "/BlogEventHandler.dll";
        qDebug () <<strPluginPath;
        QSharedPointer<ctkPlugin> plugin = pContext->installPlugin (
                    QUrl::fromLocalFile (strPluginPath));

        plugin->start ();
    } catch (const ctkPluginException &e)
    {
        qDebug () << "failed to start blogEventHandler plugin " << e.what ()
                  << e.message ();
        return -1;
    }

    // 启动 blogManager 插件
    try {
        QSharedPointer<ctkPlugin> plugin = pContext->installPlugin (
                    QUrl::fromLocalFile (strPath + "/BlogManager.dll"));

        plugin->start ();

        ctkPluginContext *pContexts = plugin->getPluginContext ();

    } catch (const ctkPluginException &e)
    {
        qDebug () << "failed to start BlogManager plugin " << e.what ();
        return -1;
    }

    // 停止插件
    ctkPluginFrameworkLauncher::stop ();

    return a.exec();
}
