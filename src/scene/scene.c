#include "scene/scene.h"
#include "core/uuid.h"
#include "memory/arena.h"

void
scene_startup(CSceneState *state)
{
    state->entities = MemoryAllocArray(CEntity, SCENE_ENTITIES_MAX);
    MemoryZeroArray(state->entities, CEntity, SCENE_ENTITIES_MAX);

    state->entities_selected = MemoryAllocArray(CEntityID, SCENE_ENTITIES_MAX);
    MemoryZeroArray(state->entities_selected, CEntityID, SCENE_ENTITIES_MAX);
}

void
scene_update(CSceneState *state, f32 dt)
{
}

void
scene_shutdown(CSceneState *state)
{
}

void
scene_clear(CSceneState *state)
{
}

CEntity *
scene_entity_create(CSceneState *state)
{
    CEntity *result = state->entities + state->entities_count;
    result->uuid    = uuid_generate();
    result->scale   = v3(1.0f, 1.0f, 1.0f);
    result->flags   = EntityFlag_Everything;
    state->entities_count++;
    return result;
}

void
scene_entity_destroy(CSceneState *state, CEntity *entity)
{
    state->entities_count--;
    MemoryCopyStruct(entity, state->entities + state->entities_count - 1,
                     CEntity);
    // MemoryZeroStruct(entity, CEntity);
}
