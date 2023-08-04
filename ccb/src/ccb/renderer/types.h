#pragma once

#include "ccb/container/string.h"
#include "ccb/math/vector.h"

#define R_TRIANGLES_MAX 4096
#define R_VERTICES_MAX  R_TRIANGLES_MAX * 3

typedef struct CVertex2d
{
    CVector2 position;
    CVector4 color;
    CVector2 uv;
} CVertex2d;

typedef struct CVertex3d
{
    CVector3 position;
    CVector4 color;
    CVector2 uv;
    CVector3 normal;
    CVector3 tangent;
} CVertex3d;

typedef struct CTexture
{
    u32     uuid;
    CString path;
} CTexture;

typedef struct CRenderBatch
{
    CVertex3d traiangles[R_VERTICES_MAX];
    u32       traiangle_count;

    u32 textures[8];
    u32 texture_count;
} CRenderBatch;
