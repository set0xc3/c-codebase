#pragma once

#include "base/defines.h"
#include "core/entity.h"

#define SCENE_ENTITIES_MAX 1000

typedef struct CSceneState
{
    char *path;
    b8    edited;
    b8    dirtied;

    CEntityID *entities_selected;
    u64        entities_selected_count;
    CEntity   *entities;
    u64        entities_count;
} CSceneState;

API void scene_startup(CSceneState *state);
API void scene_update(CSceneState *state, f32 dt);
API void scene_shutdown(CSceneState *state);
API void scene_clear(CSceneState *state);

API CEntity *scene_entity_create(CSceneState *state);
API void     scene_entity_destroy(CSceneState *state, CEntity *entity);
