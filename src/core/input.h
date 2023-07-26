#pragma once

#include "base/defines.h"
#include "memory/arena.h"

typedef enum CMouseButton
{
    MouseButton_Left,
    MouseButton_Middle,
    MouseButton_Right,
    MouseButton_Count,
} CMouseButton;

typedef enum CKeyCode
{
    KeyCode_A,
    KeyCode_D,
    KeyCode_W,
    KeyCode_S,
    KeyCode_Q,
    KeyCode_E,
    KeyCode_Escape,
    KeyCode_Count,
} CKeyCode;

typedef struct CKeyboardState
{
    b8 keys[KeyCode_Count];
} CKeyboardState;

typedef struct CMouseState
{
    i32 x, y;
    i32 wheel;
    b8  buttons[MouseButton_Count];
} CMouseState;

typedef struct CInputState
{
    CKeyboardState keyboard_current;
    CKeyboardState keyboard_previous;

    CMouseState mouse_current;
    CMouseState mouse_previous;
} CInputState;

API void input_startup(CInputState *state, CMemoryArena *arena);
API void input_shutdown(CInputState *state);

API void input_button_process(CInputState *state, u32 button, b8 pressed);
API void input_key_process(CInputState *state, u32 key, b8 pressed);
API void input_mouse_motion_process(CInputState *state, i32 x, i32 y);
API void input_mouse_scroll_process(CInputState *state, i32 delta);

API void input_update(CInputState *state);
API b8   input_button_pressed(CInputState *state, u32 button);
API b8   input_button_down(CInputState *state, u32 button);
API b8   input_button_up(CInputState *state, u32 button);
API b8   input_key_pressed(CInputState *state, u32 key);
API b8   input_key_down(CInputState *state, u32 key);
API b8   input_key_up(CInputState *state, u32 key);
API void input_mouse_position_get(CInputState *state, i32 *x, i32 *y);
API void input_mouse_wheel_get(CInputState *state, i32 *delta);
