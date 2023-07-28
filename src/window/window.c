#include "window/window.h"
#include "core/logger.h"

b8
window_open(CWindow *state, const char *title, i32 xpos, i32 ypos, i32 width,
            i32 height)
{
    state->title       = title;
    state->rect.x      = xpos;
    state->rect.y      = ypos;
    state->rect.width  = width;
    state->rect.height = height;

    u32 window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    state->handle    = SDL_CreateWindow(state->title, state->rect.x,
                                        state->rect.y, state->rect.width,
                                        state->rect.height, window_flags);
    if (!state->handle)
    {
        LOG_ERROR("[SDL] Failed create window\n");
        return false;
    }

    return true;
}

b8
window_close(CWindow *state)
{
    SDL_DestroyWindow(state->handle);

    return true;
}
