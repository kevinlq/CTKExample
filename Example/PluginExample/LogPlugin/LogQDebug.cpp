#include "LogQDebug.h"

#include <QDateTime>
#include <QDebug>
#include <QStringList>

LogQDebug::LogQDebug()
    : m_nLogLevel(ctkLogService::LOG_DEBUG)
{
}

void LogQDebug::log(int nLevel, const QString &strMessage, const std::exception *pException, const char *file, const char *function, int line)
{
    Q_UNUSED(function)

    QString s = QDateTime::currentDateTime().toString(Qt::ISODate)
            .append(" - ").append(strMessage);

    if (pException != 0)
    {
        s.append(" (").append(pException->what()).append(")");
    }

    if (file)
    {
        s.append(" [at ").append(file).append(":").append(QString::number(line)).append("]");
    }

    if (nLevel == ctkLogService::LOG_WARNING)
    {
        qWarning() << s;
    }
    else if (nLevel == ctkLogService::LOG_ERROR)
    {
        qCritical() << s;
    }
    else
    {
        qDebug() << s;
    }
}

void LogQDebug::log(const ctkServiceReference &sr, int nLevel, const QString &strMessage, const std::exception *pExcetpion, const char *file, const char *function, int line)
{
    Q_UNUSED(function)

    QString s = QDateTime::currentDateTime().toString(Qt::ISODate)
            .append(" - [");

    s.append(sr.getProperty(ctkPluginConstants::SERVICE_ID).toString());
    s.append(";");
    QStringList clazzes = sr.getProperty(ctkPluginConstants::OBJECTCLASS).toStringList();
    int i = 0;

    foreach (QString clazz, clazzes)
    {
        if (i > 0) s.append(",");
        s.append(clazz);
    }

    s.append(strMessage);

    if(pExcetpion != 0)
    {
        s.append(" (").append(pExcetpion->what()).append(")");
    }

    if (file)
    {
        s.append(" [at ").append(file).append(":").append(QString::number(line)).append("]");
    }

    if (nLevel == ctkLogService::LOG_WARNING)
    {
        qWarning() << s;
    }
    else if (nLevel == ctkLogService::LOG_ERROR)
    {
        qCritical() << s;
    }
    else
    {
        qDebug() << s;
    }
}

int LogQDebug::getLogLevel() const
{
    return m_nLogLevel;
}
