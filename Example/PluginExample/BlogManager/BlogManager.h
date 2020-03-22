#ifndef BLOGMANAGER_H
#define BLOGMANAGER_H

#include <QString>

class ctkPluginContext;

typedef struct st_BlogInfo
{
    QString m_strTitle;
    QString m_strAuthor;
    QString m_strContent;

    st_BlogInfo()
        :m_strTitle("")
        , m_strAuthor("")
        , m_strContent("")
    {}
}Blog;

class BlogManager
{
public:
    BlogManager(ctkPluginContext *pContent);

    // 发布事件
    void publishBlog(const Blog& blog);

private:
    ctkPluginContext *m_pContent;
};

#endif // BLOGMANAGER_H
