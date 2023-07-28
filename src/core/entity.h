#pragma once

#include "base/defines.h"
#include "core/uuid.h"
#include "math/vector.h"

typedef CUUID CEntityID;

typedef enum CEntityFlags
{
    EntityFlag_Active     = 1 << 0,
    EntityFlag_Renderable = 1 << 1,
    EntityFlag_Everything = 0xFFFFFFFF,
} CEntityFlags;

typedef struct CEntity
{
    CEntityID    uuid;
    CEntityFlags flags;
    b8           enabled;

    CVector3 position;
    CVector4 quaternion;
    CVector3 scale;
} CEntity;
