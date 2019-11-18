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

    Blog blog;
    blog.m_strTitle = "CTK Event Admin";
    blog.m_strContent = "This is a Simple blog";
    blog.m_strAuthor = "devstone";

    m_pBlogManager->publishBlog (blog);
}

void BlogManagerActivator::stop(ctkPluginContext *pContent)
{
    Q_UNUSED(pContent);
}
