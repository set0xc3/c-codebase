#pragma once

#include "ccb/base/defines.h"
#include "ccb/math/types.h"

#define RENDERER_TRIANGLES_MAX 4096
#define RENDERER_VERTICES_MAX  RENDERER_TRIANGLES_MAX * 3

typedef struct CRendererState
{
    u32 vao;
    u32 vbo;
    u32 shader;

    CMatrix4 projection;

    CVertex3d traiangles[RENDERER_VERTICES_MAX];
    u64       traiangle_count;
} CRendererState;

API void renderer_startup(CRendererState *state);
API void renderer_shutdown(CRendererState *state);
