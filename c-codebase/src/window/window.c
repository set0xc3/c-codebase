#include "window/window.h"
#include "core/logger.h"
#include "memory/arena.h"

b8
window_open(CWindow *out_window, const char *title, i32 xpos, i32 ypos,
            i32 width, i32 height)
{
    out_window = MemoryAllocStruct(CWindow);
    MemoryZeroStruct(out_window, CWindow);

    out_window->title       = title;
    out_window->rect.x      = xpos;
    out_window->rect.y      = ypos;
    out_window->rect.width  = width;
    out_window->rect.height = height;

    u32 window_flags   = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    out_window->handle = SDL_CreateWindow(
        out_window->title, out_window->rect.x, out_window->rect.y,
        out_window->rect.width, out_window->rect.height, window_flags);
    if (!out_window->handle)
    {
        LOG_ERROR("[SDL] Failed create window\n");
        MemoryFree(out_window);
        return false;
    }

    return true;
}

b8
window_close(CWindow *window)
{
    if (window)
    {
        SDL_DestroyWindow(window->handle);
        MemoryFree(window);
    }

    return true;
}
