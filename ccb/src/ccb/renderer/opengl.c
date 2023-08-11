#include "ccb/renderer/opengl.h"
#include "ccb/renderer/types.h"

#include <glad/glad.h>

COpenGLState
opengl_init(void)
{
    COpenGLState gl = { 0 };

    if (gladLoadGL() == 0)
    {
        LOG_ERROR("[GL] Failed load glad\n");
        exit(1);
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glGenVertexArrays(1, &gl.vao);
    glBindVertexArray(gl.vao);

    glGenBuffers(1, &gl.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, gl.vbo);
    glBufferData(GL_ARRAY_BUFFER, R_VERTICES_MAX * sizeof(CVertex3d), NULL,
                 GL_DYNAMIC_DRAW);
    return gl;
}

void
opengl_destroy(void)
{
}

void
opengl_begin_frame(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(255, 255, 255, 255);
}

void
opengl_end_frame(void)
{
}

void
opengl_flush(COpenGLState *gl, CRenderBatch *render_batch)
{
    if (render_batch->traiangle_count == 0)
    {
        return;
    }

    glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0,
                    render_batch->traiangle_count * 3 * sizeof(CVertex3d),
                    render_batch->traiangles);
    glUseProgram(gl->shader);
    glBindVertexArray(gl->vao);
    glDrawArrays(GL_TRIANGLES, 0, render_batch->traiangle_count * 3);
}
