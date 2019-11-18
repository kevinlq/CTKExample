#include "BlogManager.h"

#include <service/event/ctkEventAdmin.h>
#include <ctkPluginContext.h>

#include <QDebug>


BlogManager::BlogManager(ctkPluginContext *pContent)
    :m_pContent(pContent)
{

}

void BlogManager::publishBlog(const Blog &blog)
{
    if (Q_NULLPTR == m_pContent)
    {
        return;
    }

    ctkServiceReference ref = m_pContent->getServiceReference <ctkEventAdmin>();

    if ( ref)
    {
        ctkEventAdmin *pEventAdmin = m_pContent->getService <ctkEventAdmin>(ref);

        if ( Q_NULLPTR == pEventAdmin)
        {
            return;
        }

        ctkDictionary props;
        props["title"]  = blog.m_strTitle;
        props["content"]    = blog.m_strContent;
        props["author"] = blog.m_strAuthor;

        ctkEvent event("org/commontk/bloggenerator/published", props);

        qDebug () << "publisher send message:" << props;

        pEventAdmin->sendEvent (event);
    }
}
