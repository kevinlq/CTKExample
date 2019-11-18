#include "BlogEventHandlerActivator.h"

#include "BlogEventHandler.h"

#include <service/event/ctkEventConstants.h>

BlogEventHandlerActivator::BlogEventHandlerActivator()
    :m_pEventHandler(Q_NULLPTR)
{

}

void BlogEventHandlerActivator::start(ctkPluginContext *pContent)
{
    if ( Q_NULLPTR == pContent)
    {
        return;
    }

    if (Q_NULLPTR == m_pEventHandler)
    {
        m_pEventHandler = new(std::nothrow) BlogEventHandler;
    }

    ctkDictionary props;
    props[ctkEventConstants::EVENT_TOPIC]   = "org/commontk/bloggenerator/published";
    props[ctkEventConstants::EVENT_FILTER]  = "(author=devstone)";

    pContent->registerService<ctkEventHandler>(m_pEventHandler, props);
}

void BlogEventHandlerActivator::stop(ctkPluginContext *pContent)
{
    Q_UNUSED(pContent);
}
