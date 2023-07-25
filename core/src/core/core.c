#include "core/core.h"

#include "core/container/string8.c"
#include "core/container/vector2.c"
#include "core/container/vector3.c"
#include "core/container/vector4.c"
#include "core/debug/debug.c"
#include "core/debug/memory.c"
#include "core/debug/profiler.c"
#include "core/event/event.c"
#include "core/input/input.c"
#include "core/library/library.c"
#include "core/logger/logger.c"
#include "core/math/math.c"
#include "core/memory/arena.c"
#include "core/module/module.c"
#include "core/scene/scene.c"
#include "core/uuid/uuid.c"
#include "core/window/window.c"

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

void
core_startup(CCoreState *core)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) < 0)
    {
        LOG_ERROR("SDL could not initialize: %s\n", SDL_GetError());
    }
}

void
core_update(CCoreState *core)
{
    input_update(core);
    core_poll_event(core);
}

void
core_shutdown(CCoreState *core)
{
    SDL_Quit();
}

b8
core_poll_event(CCoreState *core)
{
    CEvent    send_event = { 0 };
    SDL_Event raw_event  = { 0 };

    while (SDL_PollEvent(&raw_event))
    {
        switch (raw_event.type)
        {
        case SDL_QUIT:
            event_fire(core, EventCode_AppQuit, send_event);
            break;

        case SDL_WINDOWEVENT:
        {
            if (raw_event.window.event == SDL_WINDOWEVENT_RESIZED)
            {
                send_event.data.i32[0] = raw_event.window.data1;
                send_event.data.i32[1] = raw_event.window.data2;
                event_fire(core, EventCode_WindowResized, send_event);
            }
        }
        break;

        case SDL_MOUSEMOTION:
            input_mouse_motion_process(core, raw_event.motion.x,
                                       raw_event.motion.y);
            break;

        case SDL_MOUSEWHEEL:
            input_mouse_scroll_process(core, raw_event.wheel.y);
            break;

        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
        {
            CMouseButton button = MouseButton_Count;
            b8 pressed = raw_event.button.state == SDL_PRESSED ? true : false;

            switch (raw_event.button.button)
            {
            case SDL_BUTTON_LEFT:
                button = MouseButton_Left;
                break;
            case SDL_BUTTON_MIDDLE:
                button = MouseButton_Middle;
                break;
            case SDL_BUTTON_RIGHT:
                button = MouseButton_Right;
                break;
            }

            if (button != MouseButton_Count)
            {
                input_button_process(core, button, pressed);
            }
        }
        break;

        case SDL_KEYDOWN:
        case SDL_KEYUP:
        {
            CKeyCode key = KeyCode_Count;
            b8 pressed   = raw_event.key.state == SDL_PRESSED ? true : false;

            switch (raw_event.key.keysym.sym)
            {
            case SDLK_w:
                key = KeyCode_W;
                break;
            case SDLK_s:
                key = KeyCode_S;
                break;
            case SDLK_a:
                key = KeyCode_A;
                break;
            case SDLK_d:
                key = KeyCode_D;
                break;
            case SDLK_q:
                key = KeyCode_Q;
                break;
            case SDLK_e:
                key = KeyCode_E;
                break;
            case SDLK_ESCAPE:
                key = KeyCode_Escape;
                break;
            }

            if (key != KeyCode_Count)
            {
                input_key_process(core, key, pressed);
            }
        }
        break;
        }
    }

    return true;
}

void
core_sleep(CCoreState *core, u32 ms)
{
    SDL_Delay(ms);
}

u64
core_perf_counter(CCoreState *core)
{
    return SDL_GetPerformanceCounter();
}

u64
core_perf_frequency(CCoreState *core)
{
    return SDL_GetPerformanceFrequency();
}
