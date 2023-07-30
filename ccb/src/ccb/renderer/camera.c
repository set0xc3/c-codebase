#include "ccb/renderer/camera.h"

CCamera
camera_create(void)
{
    CCamera camera;

    camera_reset(&camera);

    return camera;
}

void
camera_reset(CCamera *camera)
{
    if (camera)
    {
        camera->euler_rotation = vec3_zero();
        camera->position       = vec3_zero();
        camera->is_dirty       = false;
        camera->view_matrix    = mat4_identity();
    }
}

CVector3
camera_position_get(const CCamera *camera)
{
    if (camera)
    {
        return camera->position;
    }

    return vec3_zero();
}

void
camera_position_set(CCamera *camera, CVector3 position)
{
    if (camera)
    {
        camera->position = position;
        camera->is_dirty = true;
    }
}

CVector3
camera_rotation_euler_get(const CCamera *camera)
{
    if (camera)
    {
        return camera->euler_rotation;
    }

    return vec3_zero();
}

void
camera_rotation_euler_set(CCamera *camera, CVector3 rotation)
{
    if (camera)
    {
        camera->euler_rotation.x = math_deg_to_rad(rotation.x);
        camera->euler_rotation.y = math_deg_to_rad(rotation.y);
        camera->euler_rotation.z = math_deg_to_rad(rotation.z);
        camera->is_dirty         = true;
    }
}

CMatrix4
camera_view_get(CCamera *camera)
{
    if (camera)
    {
        if (camera->is_dirty)
        {
            CMatrix4 rotation    = mat4_euler_xyz(camera->euler_rotation.x,
                                                  camera->euler_rotation.y,
                                                  camera->euler_rotation.z);
            CMatrix4 translation = mat4_translation(camera->position);

            camera->view_matrix = mat4_mul(rotation, translation);
            camera->view_matrix = mat4_inverse(camera->view_matrix);

            camera->is_dirty = false;
        }

        return camera->view_matrix;
    }

    return mat4_identity();
}

CVector3
camera_forward_get(CCamera *camera)
{
    if (camera)
    {
        CMatrix4 view = camera_view_get(camera);
        return mat4_forward(view);
    }
    return vec3_zero();
}

CVector3
camera_backward_get(CCamera *camera)
{
    if (camera)
    {
        CMatrix4 view = camera_view_get(camera);
        return mat4_backward(view);
    }
    return vec3_zero();
}

CVector3
camera_left_get(CCamera *camera)
{
    if (camera)
    {
        CMatrix4 view = camera_view_get(camera);
        return mat4_left(view);
    }
    return vec3_zero();
}

CVector3
camera_right_get(CCamera *camera)
{
    if (camera)
    {
        CMatrix4 view = camera_view_get(camera);
        return mat4_right(view);
    }
    return vec3_zero();
}

CVector3
camera_up_get(CCamera *camera)
{
    if (camera)
    {
        CMatrix4 view = camera_view_get(camera);
        return mat4_up(view);
    }
    return vec3_zero();
}

CVector3
camera_down_get(CCamera *camera)
{
    if (camera)
    {
        CMatrix4 view = camera_view_get(camera);
        return mat4_down(view);
    }
    return vec3_zero();
}

void
camera_move_forward(CCamera *camera, f32 amount)
{
    if (camera)
    {
        CVector3 direction = camera_forward_get(camera);
        direction          = vec3_mul_scalar(direction, amount);
        camera->position   = vec3_add(camera->position, direction);
        camera->is_dirty   = true;
    }
}

void
camera_move_backward(CCamera *camera, f32 amount)
{
    if (camera)
    {
        CVector3 direction = camera_backward_get(camera);
        direction          = vec3_mul_scalar(direction, amount);
        camera->position   = vec3_add(camera->position, direction);
        camera->is_dirty   = true;
    }
}

void
camera_move_left(CCamera *camera, f32 amount)
{
    if (camera)
    {
        CVector3 direction = camera_left_get(camera);
        direction          = vec3_mul_scalar(direction, amount);
        camera->position   = vec3_add(camera->position, direction);
        camera->is_dirty   = true;
    }
}

void
camera_move_right(CCamera *camera, f32 amount)
{
    if (camera)
    {
        CVector3 direction = camera_right_get(camera);
        direction          = vec3_mul_scalar(direction, amount);
        camera->position   = vec3_add(camera->position, direction);
        camera->is_dirty   = true;
    }
}

void
camera_move_up(CCamera *camera, f32 amount)
{
    if (camera)
    {
        CVector3 direction = camera_up_get(camera);
        direction          = vec3_mul_scalar(direction, amount);
        camera->position   = vec3_add(camera->position, direction);
        camera->is_dirty   = true;
    }
}

void
camera_move_down(CCamera *camera, f32 amount)
{
    if (camera)
    {
        CVector3 direction = camera_down_get(camera);
        direction          = vec3_mul_scalar(direction, amount);
        camera->position   = vec3_add(camera->position, direction);
        camera->is_dirty   = true;
    }
}

void
camera_yaw(CCamera *camera, f32 amount)
{
    if (camera)
    {
        camera->euler_rotation.y += amount;
        camera->is_dirty = true;
    }
}

void
camera_pitch(CCamera *camera, f32 amount)
{
    if (camera)
    {
        camera->euler_rotation.x += amount;

        // Clamp to avoid Gimball lock.
        static const f32 limit
            = 1.55334306f; // 89 degrees, or equivalent to deg_to_rad(89.0f);
        camera->euler_rotation.x
            = CLAMP(camera->euler_rotation.x, -limit, limit);

        camera->is_dirty = true;
    }
}
