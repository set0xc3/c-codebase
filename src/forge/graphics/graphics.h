#ifndef FORGE_GRAPHICS_H
#define FORGE_GRAPHICS_H

#include "forge/asset/asset.h"
#include "forge/base/base.h"
#include "forge/container/vector.h"
#include "forge/graphics/window.h"
#include "forge/platform/platform.h"

typedef struct Vertex
{
    V3F position;
    V3F color;
    V2F uv;
} Vertex;

typedef V4F Rect;

typedef struct GFXState GFXState;

EXPORT_LIB void         gfx_init(void);
EXPORT_LIB void         gfx_destroy(void);
EXPORT_LIB b32          gfx_update(void);
EXPORT_LIB b32          gfx_quit_is(void);
EXPORT_LIB WindowState *gfx_window_get(void);
EXPORT_LIB void         gfx_window_position_set(V2F position);
EXPORT_LIB V2F          gfx_window_position_get(void);
EXPORT_LIB void         gfx_window_size_set(V2F size);
EXPORT_LIB V2F          gfx_window_size_get(void);
EXPORT_LIB void         gfx_window_title_set(const char *title);
EXPORT_LIB const char  *gfx_window_title_get(void);
EXPORT_LIB void         gfx_begin(void);
EXPORT_LIB void         gfx_end(void);

EXPORT_LIB void gfx_draw_rect(V3F position, V3F size, V4F color);
EXPORT_LIB void gfx_draw_rect_fill(V3F position, V2F size, V4F color);
EXPORT_LIB void gfx_draw_image(Image *image, V3F position, V2F size,
                               V4F color);
EXPORT_LIB void gfx_draw_line(V3F a, V3F b, V4F color);

#endif // FORGE_GRAPHICS_H
