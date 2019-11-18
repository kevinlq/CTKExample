#ifndef BLOGEVENTHANDLER_H
#define BLOGEVENTHANDLER_H

#include <QObject>
#include <service/event/ctkEventHandler.h>

class BlogEventHandler : public QObject, public ctkEventHandler
{
    Q_OBJECT
    Q_INTERFACES(ctkEventHandler)
public:
    BlogEventHandler();

public:
    void handleEvent (const ctkEvent &event) Q_DECL_OVERRIDE;
};

#endif // BLOGEVENTHANDLER_H
