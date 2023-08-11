#include "ccb/math/transform.h"

CTransform
transform_create(CVector3 position, CQuaternion rotation, CVector3 scale)
{
    CTransform transform;

    transform.position = position;
    transform.rotation = rotation;
    transform.scale    = scale;
    transform.local    = mat4_identity();
    transform.parent   = 0;

    return transform;
}

CTransform
transform_from_position(CVector3 position)
{
    CTransform transform;

    transform.position = position;
    transform.rotation = quat_identity();
    transform.scale    = vec3_zero();
    transform.local    = mat4_identity();
    transform.parent   = 0;
    transform.is_dirty = true;

    return transform;
}

CTransform
transform_from_rotation(CQuaternion rotation)
{
    CTransform transform;

    transform.position = vec3_zero();
    transform.rotation = rotation;
    transform.scale    = vec3_zero();
    transform.local    = mat4_identity();
    transform.parent   = 0;
    transform.is_dirty = true;

    return transform;
}

CTransform
transform_from_scale(CVector3 scale)
{
    CTransform transform;

    transform.position = vec3_zero();
    transform.rotation = quat_identity();
    transform.scale    = scale;
    transform.local    = mat4_identity();
    transform.parent   = 0;
    transform.is_dirty = true;

    return transform;
}

void
transform_translate(CTransform *transform, CVector3 translation)
{
    transform->position = vec3_add(transform->position, translation);
    transform->is_dirty = true;
}

void
transform_rotate(CTransform *transform, CQuaternion rotation)
{
    transform->rotation = quat_mul(transform->rotation, rotation);
    transform->is_dirty = true;
}

void
transform_scale(CTransform *transform, CVector3 scale)
{
    transform->scale    = vec3_mul(transform->scale, scale);
    transform->is_dirty = true;
}

CMatrix4
transform_local_get(CTransform *transform)
{
    if (transform)
    {
        if (transform->is_dirty)
        {
            CMatrix4 tr         = mat4_mul(quat_to_mat4(transform->rotation),
                                           mat4_translation(transform->position));
            tr                  = mat4_mul(mat4_scale(transform->scale), tr);
            transform->local    = tr;
            transform->is_dirty = false;
        }

        return transform->local;
    }
    return mat4_identity();
}

CMatrix4
transform_world_get(CTransform *transform)
{
    if (transform)
    {
        CMatrix4 local = transform_local_get(transform);
        if (transform->parent)
        {
            CMatrix4 parent = transform_world_get(transform->parent);
            return mat4_mul(local, parent);
        }
        return local;
    }
    return mat4_identity();
}

CVector3
transform_position_get(const CTransform *transform)
{
    return transform->position;
}

void
transform_position_set(CTransform *transform, CVector3 position)
{
    transform->position = position;
    transform->is_dirty = true;
}

CQuaternion
transform_rotation_get(const CTransform *transform)
{
    return transform->rotation;
}

void
transform_rotation_set(CTransform *transform, CQuaternion rotation)
{
    transform->rotation = rotation;
    transform->is_dirty = true;
}

CVector3
transform_scale_get(const CTransform *transform)
{
    return transform->scale;
}

void
transform_scale_set(CTransform *transform, CVector3 scale)
{
    transform->scale    = scale;
    transform->is_dirty = true;
}

CTransform *
transform_parent_get(CTransform *transform)
{
    return transform->parent;
}

void
transform_parent_set(CTransform *transform, CTransform *parent)
{
    transform->parent   = parent;
    transform->is_dirty = true;
}
