#pragma once

#include "ccb/base/defines.h"

#include <SDL2/SDL.h>

typedef struct CWindow
{
    SDL_Window   *handle;
    SDL_GLContext context;
    SDL_Texture  *texture;
    const char   *title;
    struct
    {
        i32 x, y;
        i32 width, height;
    } rect;
} CWindow;

API CWindow *window_open(const char *title, i32 xpos, i32 ypos, i32 width,
                         i32 height);
API b8       window_close(CWindow *window);
API void     window_swap_buffer(CWindow *window);
