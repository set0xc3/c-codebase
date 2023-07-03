#include "forge/graphics/window.h"

struct WindowEvent
{
    u64 *handle;
    i32  kind;
    i32  code;
    i32  state;
    i32  xwheel, ywheel;
    i32  xpos, ypos;
    i32  width, height;
};

struct WindowState
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
};
