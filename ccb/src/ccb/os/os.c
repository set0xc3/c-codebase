#include "ccb/os/os.h"
#include "ccb/container/string.h"
#include "ccb/core/event.h"
#include "ccb/core/input.h"
#include "ccb/core/logger.h"

#include <SDL2/SDL.h>

b8
os_startup(void)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) < 0)
    {
        LOG_ERROR("SDL could not initialize: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

b8
os_shutdown(void)
{
    SDL_Quit();

    return true;
}

b8
os_poll_event(void)
{
    CEvent    send_event = { 0 };
    SDL_Event raw_event  = { 0 };

    while (SDL_PollEvent(&raw_event))
    {
        switch (raw_event.type)
        {
        case SDL_QUIT:
            // event_fire(EventCode_AppQuit, send_event);
            return false;

        case SDL_WINDOWEVENT:
        {
            if (raw_event.window.event == SDL_WINDOWEVENT_RESIZED)
            {
                send_event.data.i32[0] = raw_event.window.data1;
                send_event.data.i32[1] = raw_event.window.data2;
                // event_fire(EventCode_WindowResized, send_event);
            }
        }
        break;

        case SDL_MOUSEMOTION:
            // input_mouse_motion_process(raw_event.motion.x,
            // raw_event.motion.y);
            break;

        case SDL_MOUSEWHEEL:
            // input_mouse_scroll_process(raw_event.wheel.y);
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
                // input_button_process(button, pressed);
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
                // input_key_process(key, pressed);
            }
        }
        break;
        }
    }

    return true;
}

void
os_sleep(u32 ms)
{
    SDL_Delay(ms);
}

u64
os_perf_counter(void)
{
    return SDL_GetPerformanceCounter();
}

u64
os_perf_frequency(void)
{
    return SDL_GetPerformanceFrequency();
}

CLibrary
os_library_load(const char *path)
{
    CLibrary result = { 0 };

    char *dot      = ".";
    u64   dot_size = strlen(dot);

    u64      size     = strlen(path) + strlen(LIBRARY_EXTENSION) + dot_size;
    CString8 path_ext = { (u8 *)alloca(size), size };
    strncpy((char *)path_ext.str, path, path_ext.size);

    strncat((char *)path_ext.str, dot, path_ext.size);
    strncat((char *)path_ext.str, LIBRARY_EXTENSION, path_ext.size);

    result.handle = SDL_LoadObject((const char *)path_ext.str);
    if (result.handle == NULL)
    {
        LOG_ERROR("[SDL] %s\n", SDL_GetError());
    }

    result.is_valid = true;

    return result;
}

void
os_library_unload(CLibrary *library)
{
    SDL_UnloadObject(library->handle);
    MemoryFree(library);
}

void *
os_library_load_function(CLibrary *library, const char *name)
{
    return SDL_LoadFunction(library->handle, name);
}
