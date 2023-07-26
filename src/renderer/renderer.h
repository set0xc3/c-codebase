#pragma once

#include "base/defines.h"

#define RENDERER_TRIANGLES_MAX 2048
#define RENDERER_VERTICES_MAX  RENDERER_TRIANGLES_MAX * 3

typedef struct CRendererVertex
{
    f32 position[3];
    f32 color[4];
    f32 uv[2];
} CRendererVertex;

typedef struct CRendererState
{
    u32 vao;
    u32 vbo;
    u32 shader;

    // TODO
    // mat4 projection;

    CRendererVertex traiangles[RENDERER_VERTICES_MAX];
    u64             traiangle_count;
} CRendererState;

API void renderer_startup(CRendererState *state);
API void renderer_shutdown(CRendererState *state);
