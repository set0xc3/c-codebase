#pragma once

#include "ccb/base/defines.h"
#include "ccb/math/types.h"
#include "ccb/renderer/opengl.h"
#include "ccb/renderer/types.h"

typedef struct CRendererState
{
    COpenGLState gl;
    CRenderBatch render_batch;

    CMatrix4 projection;
} CRendererState;

API CRendererState *renderer_startup(void);
API void            renderer_shutdown(CRendererState *state);

API void renderer_begin_frame(CRendererState *r);
API void renderer_end_frame(CRendererState *r);
API void renderer_draw_rect(CRendererState *state, CVector2 position,
                            CVector2 size, CColor color);
