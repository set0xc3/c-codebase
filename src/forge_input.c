#include "forge_input.h"
#include "forge_vector2.h"

#include <stdbool.h>
#include <string.h>

void input_button_callback(InputState *input, i32 code, i32 state) {
    input->button[code] = state;
}

void input_key_callback(InputState *input, i32 code, i32 state) {
    input->key[code] = state;
}

void input_mouse_position_callback(InputState *input, Vector2 position) {
    input->position = position;
}

void input_scroll_callback(InputState *input, Vector2 delta) {
    input->wheel = delta;
}

void input_update(InputState *input) {
    memcpy(input->last_key, input->key, sizeof(input->key));
    memcpy(input->last_button, input->button, sizeof(input->button));

    memset(&input->wheel, 0, sizeof(input->wheel));
}

b32 input_button_pressed(InputState *input, i32 button) {
    return input->last_button[button] && input->button[button];
}

b32 input_button_down(InputState *input, i32 button) {
    return !input->last_button[button] && input->button[button];
}

b32 input_button_up(InputState *input, i32 button) {
    return input->last_button[button] && !input->button[button];
}

b32 input_key_pressed(InputState *input, i32 key) {
    return input->last_key[key] && input->key[key];
}

b32 input_key_down(InputState *input, i32 key) {
    return !input->last_key[key] && input->key[key];
}

b32 input_key_up(InputState *input, i32 key) {
    return input->last_key[key] && !input->key[key];
}

Vector2 input_mouse_get_position(InputState *input) {
    return input->position;
}

Vector2 input_mouse_get_wheel(InputState *input) {
    return input->wheel;
}
