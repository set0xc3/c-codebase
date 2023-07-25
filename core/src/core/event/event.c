#include "core/core.h"

b8
event_startup(CCoreState *core)
{
    core->event = MemoryAllocStruct(CEventState);
    MemoryZeroStruct(core->event, CEventState);

    core->event->listeners
        = MemoryAllocArray(CEventListener, EVENT_LISTENERS_MAX);
    MemoryZeroArray(core->event->listeners, CEventListener,
                    EVENT_LISTENERS_MAX);

    return true;
}

b8
event_shutdown(CCoreState *core)
{
    MemoryFree(core->event->listeners);
    MemoryFree(core->event);
    return true;
}

b8
event_register(CCoreState *core, u32 code, event_on_listener on_listener)
{
    if (core->event->listeners_count + 1 > EVENT_LISTENERS_MAX)
    {
        return false;
    }

    for (u64 index = 0; index < core->event->listeners_count; index++)
    {
        CEventListener *listener = core->event->listeners + index;
        if (listener->code & code && listener->callback == on_listener)
        {
            return true;
        }
    }

    CEventListener *listener
        = core->event->listeners + core->event->listeners_count;
    listener->code     = code;
    listener->callback = on_listener;
    core->event->listeners_count++;

    return true;
}

b8
event_unregister(CCoreState *core, u32 code, event_on_listener on_listener)
{
    CEventListener *top_listener
        = core->event->listeners + core->event->listeners_count - 1;
    for (u64 index = 0; index < core->event->listeners_count; index++)
    {
        CEventListener *listener = core->event->listeners + index;
        if (listener->code & code && listener->callback == on_listener)
        {
            listener->code     = top_listener->code;
            listener->callback = top_listener->callback;
            core->event->listeners_count--;

            break;
        }
    }

    return true;
}

b8
event_fire(CCoreState *core, u32 code, CEvent event)
{
    for (u64 index = 0; index < core->event->listeners_count; index++)
    {
        CEventListener *listener = core->event->listeners + index;
        if (listener->code & code && listener->callback(code, event))
        {
            break;
        }
    }

    return true;
}
