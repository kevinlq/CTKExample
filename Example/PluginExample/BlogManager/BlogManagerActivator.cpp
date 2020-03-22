#include "BlogManagerActivator.h"

#include "BlogManager.h"

BlogManagerActivator::BlogManagerActivator()
    :m_pBlogManager(Q_NULLPTR)
{
}

void BlogManagerActivator::start(ctkPluginContext *pContent)
{
    if (Q_NULLPTR == m_pBlogManager)
    {
        m_pBlogManager = new(std::nothrow) BlogManager(pContent);
    }

    for (int i = 0; i < 10; i++)
    {
        Blog blog;
        blog.m_strTitle = "CTK Event Admin";
        blog.m_strContent = QString("This is a Simple blog %1").arg(i);
        blog.m_strAuthor = QString("devstone%1").arg(i);

        m_pBlogManager->publishBlog (blog);
    }
}

void BlogManagerActivator::stop(ctkPluginContext *pContent)
{
    Q_UNUSED(pContent);
}
