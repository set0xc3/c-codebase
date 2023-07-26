#pragma once

#include "base/defines.h"

#include <SDL2/SDL.h>

typedef struct CWindow
{
    SDL_Window   *handle;
    SDL_Renderer *renderer;
    SDL_Texture  *texture;
    const char   *title;
    struct
    {
        i32 x, y;
        i32 width, height;
    } rect;
} CWindow;

API b8 window_open(CWindow *state, const char *title, i32 xpos, i32 ypos,
                   i32 width, i32 height);
API b8 window_close(CWindow *state);
API b8 window_poll_events(CWindow *state);
