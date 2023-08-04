#include "ccb/renderer/renderer.h"
#include "ccb/renderer/opengl.h"

CRendererState *
renderer_startup(void)
{
    CRendererState *out_state;
    out_state = MemoryAllocStruct(CRendererState);
    MemoryZeroStruct(out_state, CRendererState);

    opengl_init();

    return out_state;
}

void
renderer_begin_frame(CRendererState *r)
{
    r->render_batch.traiangle_count = 0;
    r->render_batch.texture_count   = 0;

    opengl_begin_frame();
}

void
renderer_end_frame(CRendererState *r)
{
    opengl_end_frame();
    opengl_flush(&r->gl, &r->render_batch);
}

void
renderer_shutdown(CRendererState *state)
{
    opengl_destroy();

    MemoryFree(state);
}

void
renderer_draw_rect(CRendererState *state, CVector2 position, CVector2 size,
                   CColor color)
{
}
