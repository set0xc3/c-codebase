#include "core/core.h"

void
scene_startup(CCoreState *core)
{
    core->scene = MemoryAllocStruct(CSceneState);
    MemoryZeroStruct(core->scene, CSceneState);

    core->scene->entities = MemoryAllocArray(CEntity, SCENE_ENTITIES_MAX);
    MemoryZeroArray(core->scene->entities, CEntity, SCENE_ENTITIES_MAX);

    core->scene->entities_selected
        = MemoryAllocArray(CEntityID, SCENE_ENTITIES_MAX);
    MemoryZeroArray(core->scene->entities_selected, CEntityID,
                    SCENE_ENTITIES_MAX);
}

void
scene_update(CCoreState *core, f32 dt)
{
}

void
scene_shutdown(CCoreState *core)
{
}

void
scene_clear(CCoreState *core)
{
}

CEntity *
scene_entity_create(CCoreState *core)
{
    CEntity *result = core->scene->entities + core->scene->entities_count;
    result->uuid    = uuid_gen();
    result->scale   = v3(1.0f, 1.0f, 1.0f);
    result->flags   = EntityFlag_Everything;
    core->scene->entities_count++;
    return result;
}

void
scene_entity_destroy(CCoreState *core, CEntity *entity)
{
    core->scene->entities_count--;
    MemoryFree(entity->uuid);
    MemoryCopyStruct(entity,
                     core->scene->entities + core->scene->entities_count - 1,
                     CEntity);
    // MemoryZeroStruct(entity, CEntity);
}
