#ifndef LOGQDEBUG_H
#define LOGQDEBUG_H

#include <service/log/ctkLogService.h>

class LogQDebug : public QObject, public ctkLogService
{
    Q_OBJECT
    Q_INTERFACES(ctkLogService)
public:
    LogQDebug();

    virtual void log(int nLevel, const QString& strMessage, const std::exception* pException = 0
            , const char* file = 0, const char*function = 0, int line = -1);

    virtual void log(const ctkServiceReference& sr, int nLevel, const QString& strMessage
             , const std::exception* pExcetpion = 0
            , const char*file = 0, const char*function = 0, int line = -1);

    virtual int getLogLevel() const;

private:
    int m_nLogLevel;
};

#endif // LOGQDEBUG_H
