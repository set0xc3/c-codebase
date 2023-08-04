#pragma once

#include "ccb/base/defines.h"
#include "ccb/renderer/types.h"

typedef struct COpenGLState
{
    u32 vao;
    u32 vbo;
    u32 shader;
} COpenGLState;

API COpenGLState opengl_init(void);
API void         opengl_destroy(void);

API void opengl_begin_frame(void);
API void opengl_end_frame(void);
API void opengl_flush(COpenGLState *gl, CRenderBatch *render_batch);
