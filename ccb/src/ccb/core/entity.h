#pragma once

#include "ccb/base/defines.h"
#include "ccb/container/string.h"
#include "ccb/core/uuid.h"
#include "ccb/math/transform.h"

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
    CString      name;
    b8           enabled;

    CTransform transform;
} CEntity;
