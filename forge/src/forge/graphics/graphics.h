#ifndef FORGE_GRAPHICS_H
#define FORGE_GRAPHICS_H

#include "forge/asset/asset.h"
#include "forge/base/base.h"
#include "forge/container/vector.h"
#include "forge/graphics/window.h"
#include "forge/platform/platform.h"

typedef struct Vertex
{
    Vector3 position;
    Vector3 color;
    Vector2 uv;
} Vertex;

typedef Vector4 Rect;

typedef struct GFXState GFXState;

EXPORT_LIB void         gfx_init(void);
EXPORT_LIB void         gfx_destroy(void);
EXPORT_LIB b32          gfx_update(void);
EXPORT_LIB b32          gfx_is_quit(void);
EXPORT_LIB WindowState *gfx_get_window(void);
EXPORT_LIB void         gfx_window_set_position(Vector2 position);
EXPORT_LIB Vector2      gfx_window_get_position(void);
EXPORT_LIB void         gfx_window_set_size(Vector2 size);
EXPORT_LIB Vector2      gfx_window_get_size(void);
EXPORT_LIB void         gfx_window_set_title(const char *title);
EXPORT_LIB const char  *gfx_window_get_title(void);
EXPORT_LIB void         gfx_begin(void);
EXPORT_LIB void         gfx_end(void);

EXPORT_LIB void gfx_draw_rect(Vector3 position, Vector3 size, Vector4 color);
EXPORT_LIB void gfx_draw_fill_rect(Vector3 position, Vector2 size,
                                   Vector4 color);
EXPORT_LIB void gfx_draw_image(Image *image, Vector3 position, Vector2 size,
                               Vector4 color);
EXPORT_LIB void gfx_draw_line(Vector3 a, Vector3 b, Vector4 color);

#endif // FORGE_GRAPHICS_H
