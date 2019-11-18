#include "BlogEventHandler.h"

#include <QDebug>

BlogEventHandler::BlogEventHandler()
{
}

void BlogEventHandler::handleEvent(const ctkEvent &event)
{
    QString strTitle = event.getProperty ("title").toString ();
    QString strContent = event.getProperty ("content").toString ();
    QString strAuthor = event.getProperty ("author").toString ();

    qDebug () << "eventHandle receive message:"
              << event.getTopic ()
              << "properties:" << "title:" << strTitle
              << "content:" << strContent
              << "author:" << strAuthor;
}
