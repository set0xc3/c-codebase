#pragma once

#include "base/defines.h"
#include "memory/arena.h"

#define EVENT_LISTENERS_MAX 1024

typedef enum CEventCode
{
    EventCode_AppQuit        = 1 << 0,
    EventCode_KeyPressed     = 1 << 1,
    EventCode_KeyReleased    = 1 << 2,
    EventCode_ButtonPressed  = 1 << 3,
    EventCode_ButtonReleased = 1 << 4,
    EventCode_MouseMotion    = 1 << 5,
    EventCode_MouseWheel     = 1 << 6,
    EventCode_WindowResized  = 1 << 7,
    EventCode_WindowClosed   = 1 << 8,
    EventCode_Everything     = 0xFFFFFFFF,
    EventCode_Count          = 9,
} CEventCode;

typedef struct CEvent CEvent;
typedef b8            event_on_listener(u32 code, CEvent event);

typedef struct CEvent
{
    // 128 bites
    union
    {
        i64 i64[2];
        u64 u64[2];
        f64 f64[2];

        i32 i32[4];
        u32 u32[4];
        f32 f32[4];

        i16 i16[8];
        u16 u16[8];

        i8 i8[16];
        u8 u8[16];

        char c[16];
    } data;
} CEvent;

typedef struct CEventListener
{
    u32                code;
    event_on_listener *callback;
} CEventListener;

typedef struct CEventState
{
    CEventListener *listeners;
    u64             listeners_count;
} CEventState;

API b8 event_startup(CEventState *state, CMemoryArena *arena);
API b8 event_shutdown(CEventState *state);
API b8 event_register(CEventState *state, u32 code,
                      event_on_listener *on_listener);
API b8 event_unregister(CEventState *state, u32 code,
                        event_on_listener *on_listener);
API b8 event_fire(CEventState *state, u32 code, CEvent event);
