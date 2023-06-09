#ifndef FORGE_INPUT_H
#define FORGE_INPUT_H

#include "forge_base_types.h"
#include "forge_platform_types.h"

#include <stdint.h>

typedef enum MouseButton {
    MOUSE_BUTTON_NULL,
    MOUSE_BUTTON_LEFT,
    MOUSE_BUTTON_MIDDLE,
    MOUSE_BUTTON_RIGHT,
    MOUSE_BUTTON_COUNT,
} MouseButton;

typedef enum KeyCode {
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

typedef struct InputState {
    b32 last_key[KEY_CODE_COUNT];
    b32 key[KEY_CODE_COUNT];

    f32 xpos, ypos;
    f32 xwheel, ywheel;
    b32 last_button[MOUSE_BUTTON_COUNT];
    b32 button[MOUSE_BUTTON_COUNT];
} InputState;

EXPORT_LIB void input_button_callback(InputState *input, i32 code, i32 state);
EXPORT_LIB void input_key_callback(InputState *input, i32 code, i32 state);
EXPORT_LIB void input_mouse_pos_callback(InputState *input, f32 xpos, f32 ypos);
EXPORT_LIB void input_scroll_callback(InputState *input, f32 xdelta,
                                      f32 ydelta);

EXPORT_LIB void input_update(InputState *input);

EXPORT_LIB b32 input_button_pressed(InputState *input, i32 button);
EXPORT_LIB b32 input_button_down(InputState *input, i32 button);
EXPORT_LIB b32 input_button_up(InputState *input, i32 button);

EXPORT_LIB b32 input_key_pressed(InputState *input, i32 key);
EXPORT_LIB b32 input_key_down(InputState *input, i32 key);
EXPORT_LIB b32 input_key_up(InputState *input, i32 key);

EXPORT_LIB void input_mouse_get_pos(InputState *input, i32 *xpos, i32 *ypos);
EXPORT_LIB void input_mouse_get_wheel(InputState *input, i32 *xdelta, i32 *ydelta);

#endif // FORGE_INPUT_H
