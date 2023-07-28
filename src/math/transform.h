#pragma once

#include "base/defines.h"
#include "math/matrix.h"
#include "math/quaternion.h"
#include "math/vector.h"

API CTransform transform_create(CVector3 position, CQuaternion rotation,
                                CVector3 scale);

API CTransform transform_from_position(CVector3 position);
API CTransform transform_from_rotation(CQuaternion rotation);
API CTransform transform_from_scale(CVector3 scale);

API void transform_translate(CTransform *transform, CVector3 translation);
API void transform_rotate(CTransform *transform, CQuaternion rotation);
API void transform_scale(CTransform *transform, CVector3 scale);

API CMatrix4 transform_local_get(CTransform *transform);
API CMatrix4 transform_world_get(CTransform *transform);

API CVector3 transform_position_get(const CTransform *transform);
API void     transform_position_set(CTransform *transform, CVector3 position);

API CQuaternion transform_rotation_get(const CTransform *transform);
API void transform_rotation_set(CTransform *transform, CQuaternion rotation);

API CVector3 transform_scale_get(const CTransform *transform);
API void     transform_scale_set(CTransform *transform, CVector3 scale);

API CTransform *transform_parent_get(CTransform *transform);
API void transform_parent_set(CTransform *transform, CTransform *parent);
