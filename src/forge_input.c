#include "forge_input.h"

#include <stdbool.h>
#include <string.h>

void input_button_callback(InputState *input, i32 code, i32 state) {
    input->button[code] = state;
}

void input_key_callback(InputState *input, i32 code, i32 state) {
    input->key[code] = state;
}

void input_mouse_pos_callback(InputState *input, f32 xpos, f32 ypos) {
    input->xpos = xpos;
    input->ypos = ypos;
}

void input_scroll_callback(InputState *input, f32 xdelta, f32 ydelta) {
    input->xwheel = xdelta;
    input->ywheel = ydelta;
}

void input_update(InputState *input) {
    memcpy(input->last_key, input->key, sizeof(input->key));
    memcpy(input->last_button, input->button, sizeof(input->button));

    input->xwheel = 0;
    input->ywheel = 0;
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

void input_mouse_get_pos(InputState *input, i32 *xpos, i32 *ypos) {
    *xpos = input->xpos;
    *ypos = input->ypos;
}

void input_mouse_get_wheel(InputState *input, i32 *xdelta, i32 *ydelta) {
    *xdelta = input->xwheel;
    *ydelta = input->ywheel;
}
