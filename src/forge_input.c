#include "forge_input.h"
#include "forge_vector2.h"

#include <stdbool.h>
#include <string.h>

global_variable InputState *g_input;

void input_init(InputState *input) {
  g_input = input;
}

void input_button_callback(i32 code, i32 state) {
    g_input->button[code] = state;
}

void input_key_callback(i32 code, i32 state) {
    g_input->key[code] = state;
}

void input_mouse_position_callback(Vector2 position) {
    g_input->position = position;
}

void input_scroll_callback(Vector2 delta) {
    g_input->wheel = delta;
}

void input_update(void) {
    memcpy(g_input->last_key, g_input->key, sizeof(g_input->key));
    memcpy(g_input->last_button, g_input->button, sizeof(g_input->button));

    memset(&g_input->wheel, 0, sizeof(g_input->wheel));
}

b32 input_button_pressed(i32 button) {
    return g_input->last_button[button] && g_input->button[button];
}

b32 input_button_down(i32 button) {
    return !g_input->last_button[button] && g_input->button[button];
}

b32 input_button_up(i32 button) {
    return g_input->last_button[button] && !g_input->button[button];
}

b32 input_key_pressed(i32 key) {
    return g_input->last_key[key] && g_input->key[key];
}

b32 input_key_down(i32 key) {
    return !g_input->last_key[key] && g_input->key[key];
}

b32 input_key_up(i32 key) {
    return g_input->last_key[key] && !g_input->key[key];
}

Vector2 input_mouse_get_position(void) {
    return g_input->position;
}

Vector2 input_mouse_get_wheel(void) {
    return g_input->wheel;
}
