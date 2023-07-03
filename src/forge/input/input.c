#include "input.h"

#include <stdbool.h>
#include <string.h>

global_variable InputState *g_input;

void
input_init(InputState *input)
{
    g_input = input;
}

void
input_button_callback(i32 code, i32 state)
{
    g_input->button[code] = state;
}

void
input_key_callback(i32 code, i32 state)
{
    g_input->key[code] = state;
}

void
input_mouse_position_callback(V2F position)
{
    g_input->position = position;
}

void
input_scroll_callback(V2F delta)
{
    g_input->wheel = delta;
}

void
input_update(void)
{
    memcpy(g_input->last_key, g_input->key, sizeof(g_input->key));
    memcpy(g_input->last_button, g_input->button, sizeof(g_input->button));

    memset(&g_input->wheel, 0, sizeof(g_input->wheel));
}

b32
input_button_pressed(i32 button)
{
    return g_input->last_button[button] && g_input->button[button];
}

b32
input_button_down(i32 button)
{
    return !g_input->last_button[button] && g_input->button[button];
}

b32
input_button_up(i32 button)
{
    return g_input->last_button[button] && !g_input->button[button];
}

b32
input_key_pressed(i32 key)
{
    return g_input->last_key[key] && g_input->key[key];
}

b32
input_key_down(i32 key)
{
    return !g_input->last_key[key] && g_input->key[key];
}

b32
input_key_up(i32 key)
{
    return g_input->last_key[key] && !g_input->key[key];
}

V2F
input_mouse_position_get(void)
{
    return g_input->position;
}

V2F
input_mouse_wheel_get(void)
{
    return g_input->wheel;
}
