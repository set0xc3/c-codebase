#ifndef FORGE_GFX_H
#define FORGE_GFX_H

#include "forge_base_types.h"
#include "forge_input.h"
#include "forge_platform_types.h"
#include "forge_vector2.h"
#include "forge_vector3.h"
#include "forge_vector4.h"
#include "forge_window.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

typedef struct Vertex {
    Vector3 position;
    Vector3 color;
    Vector2 uv;
} Vertex;

typedef Vector3 Rect;

typedef struct Sprite {
    SDL_Texture *texture;
    Rect rect;
} Sprite;

typedef struct GFXState {
    InputState *input;
    WindowState *window;
} GFXState;

EXPORT_LIB void gfx_init(GFXState *gfx);
EXPORT_LIB bool gfx_update(GFXState *gfx);

EXPORT_LIB void gfx_begin(GFXState *gfx);
EXPORT_LIB void gfx_draw_rect(GFXState *gfx, Vector3 position, Vector3 size,
                              Vector4 color);
EXPORT_LIB void gfx_draw_fill_rect(GFXState *gfx, Vector3 position,
                                   Vector2 size, Vector4 color);
EXPORT_LIB void gfx_draw_sprite(GFXState *gfx, SDL_Texture *texture,
                                Vector3 position, Vector2 size, Vector4 color);
EXPORT_LIB void gfx_draw_line(GFXState *gfx, Vector3 a, Vector3 b,
                              Vector4 color);
EXPORT_LIB void gfx_end(GFXState *gfx);

#endif // FORGE_GFX_H
