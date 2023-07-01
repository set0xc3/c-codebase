#ifndef FORGE_GRAPHICS_INPUT_H
#define FORGE_GRAPHICS_INPUT_H

#include "forge/base/base.h"
#include "forge/container/vector.h"
#include "forge/platform/platform.h"

#include <stdint.h>

typedef enum MouseButton
{
    MOUSE_BUTTON_NULL,
    MOUSE_BUTTON_LEFT,
    MOUSE_BUTTON_MIDDLE,
    MOUSE_BUTTON_RIGHT,
    MOUSE_BUTTON_COUNT,
} MouseButton;

typedef enum KeyCode
{
    KEY_CODE_NULL,
    KEY_CODE_A,
    KEY_CODE_D,
    KEY_CODE_W,
    KEY_CODE_S,
    KEY_CODE_Q,
    KEY_CODE_E,
    KEY_CODE_ESCAPE,
    KEY_CODE_COUNT,
} KeyCode;

typedef struct InputState
{
    b32 last_key[KEY_CODE_COUNT];
    b32 key[KEY_CODE_COUNT];

    b32 last_button[MOUSE_BUTTON_COUNT];
    b32 button[MOUSE_BUTTON_COUNT];

    Vector2 position;
    Vector2 wheel;
} InputState;

EXPORT_LIB void    input_init(InputState *input);
EXPORT_LIB void    input_button_callback(i32 code, i32 state);
EXPORT_LIB void    input_key_callback(i32 code, i32 state);
EXPORT_LIB void    input_mouse_position_callback(Vector2 position);
EXPORT_LIB void    input_scroll_callback(Vector2 delta);
EXPORT_LIB void    input_update(void);
EXPORT_LIB b32     input_button_pressed(i32 button);
EXPORT_LIB b32     input_button_down(i32 button);
EXPORT_LIB b32     input_button_up(i32 button);
EXPORT_LIB b32     input_key_pressed(i32 key);
EXPORT_LIB b32     input_key_down(i32 key);
EXPORT_LIB b32     input_key_up(i32 key);
EXPORT_LIB Vector2 input_mouse_get_position(void);
EXPORT_LIB Vector2 input_mouse_get_wheel(void);

#endif // FORGE_GRAPHICS_INPUT_H
