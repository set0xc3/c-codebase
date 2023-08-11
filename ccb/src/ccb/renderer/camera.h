#pragma once

#include "ccb/base/defines.h"
#include "ccb/math/matrix.h"
#include "ccb/math/vector.h"

typedef struct CCamera
{
    CVector3 position;
    CVector3 euler_rotation;
    CMatrix4 view_matrix;
    b8       is_dirty;
} CCamera;

API CCamera camera_create(void);
API void    camera_reset(CCamera *camera);

API CVector3 camera_position_get(const CCamera *camera);
API void     camera_position_set(CCamera *camera, CVector3 position);

API CVector3 camera_rotation_euler_get(const CCamera *camera);
API void     camera_rotation_euler_set(CCamera *camera, CVector3 rotation);

API CMatrix4 camera_view_get(CCamera *camera);
API CVector3 camera_forward_get(CCamera *camera);
API CVector3 camera_backward_get(CCamera *camera);
API CVector3 camera_left_get(CCamera *camera);
API CVector3 camera_right_get(CCamera *camera);
API CVector3 camera_up_get(CCamera *camera);
API CVector3 camera_down_get(CCamera *camera);

API void camera_move_forward(CCamera *camera, f32 amount);
API void camera_move_backward(CCamera *camera, f32 amount);
API void camera_move_left(CCamera *camera, f32 amount);
API void camera_move_right(CCamera *camera, f32 amount);
API void camera_move_up(CCamera *camera, f32 amount);
API void camera_move_down(CCamera *camera, f32 amount);
API void camera_yaw(CCamera *camera, f32 amount);
API void camera_pitch(CCamera *camera, f32 amount);
