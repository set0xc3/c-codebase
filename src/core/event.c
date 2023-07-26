#include "core/event.h"

b8
event_startup(CEventState *state, CMemoryArena *arena)
{
    state->listeners
        = PushArrayZero(arena, CEventListener, EVENT_LISTENERS_MAX);

    return true;
}

b8
event_shutdown(CEventState *state)
{
    MemoryFree(state);

    return true;
}

b8
event_register(CEventState *state, u32 code, event_on_listener *on_listener)
{
    if (state->listeners_count + 1 > EVENT_LISTENERS_MAX)
    {
        return false;
    }

    for (u64 index = 0; index < state->listeners_count; index++)
    {
        CEventListener *listener = state->listeners + index;
        if (listener->code & code && listener->callback == on_listener)
        {
            return true;
        }
    }

    CEventListener *listener = state->listeners + state->listeners_count;
    listener->code           = code;
    listener->callback       = on_listener;
    state->listeners_count++;

    return true;
}

b8
event_unregister(CEventState *state, u32 code, event_on_listener *on_listener)
{
    CEventListener *top_listener
        = state->listeners + state->listeners_count - 1;
    for (u64 index = 0; index < state->listeners_count; index++)
    {
        CEventListener *listener = state->listeners + index;
        if (listener->code & code && listener->callback == on_listener)
        {
            listener->code     = top_listener->code;
            listener->callback = top_listener->callback;
            state->listeners_count--;

            break;
        }
    }

    return true;
}

b8
event_fire(CEventState *state, u32 code, CEvent event)
{
    for (u64 index = 0; index < state->listeners_count; index++)
    {
        CEventListener *listener = state->listeners + index;
        if (listener->code & code && listener->callback(code, event))
        {
            break;
        }
    }

    return true;
}
