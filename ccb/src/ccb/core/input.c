#include "ccb/core/input.h"
#include "ccb/core/event.h"

void
input_startup(CInputState *state, CMemoryArena *arena)
{
    // state = PushStructZero(arena, CInputState);
}

void
input_shutdown(CInputState *state)
{
    MemoryFree(state);
}

void
input_button_process(CInputState *state, u32 button, b8 pressed)
{
    if (state->mouse_current.buttons[button] != pressed)
    {
        // log_info("button: %i, %i\n", button, pressed);

        state->mouse_current.buttons[button] = pressed;

        CEvent event      = { 0 };
        event.data.u32[0] = button;
        // event_fire(pressed ? EventCode_ButtonPressed
        //                    : EventCode_ButtonReleased,
        //            event);
    }
}

void
input_key_process(CInputState *state, u32 key, b8 pressed)
{
    if (state->keyboard_current.keys[key] != pressed)
    {
        // log_info("key: %i, %i\n", key, pressed);

        state->keyboard_current.keys[key] = pressed;

        CEvent event      = { 0 };
        event.data.u32[0] = key;
        // event_fire(pressed ? EventCode_KeyPressed : EventCode_KeyReleased,
        //            event);
    }
}

void
input_mouse_motion_process(CInputState *state, i32 x, i32 y)
{
    if (state->mouse_current.x != x || state->mouse_current.y != y)
    {
        // log_info("mouse.position: (%i, %i)\n", x, y);

        state->mouse_current.x = x;
        state->mouse_current.y = y;

        CEvent event      = { 0 };
        event.data.u32[0] = x;
        event.data.u32[1] = y;
        // event_fire(EventCode_MouseMotion, event);
    }
}

void
input_mouse_scroll_process(CInputState *state, i32 delta)
{
    if (state->mouse_current.wheel != delta)
    {
        // log_info("mouse.scroll: (%i)\n", delta);

        state->mouse_current.wheel = delta;

        CEvent event      = { 0 };
        event.data.u32[0] = delta;
        // event_fire(EventCode_MouseWheel, event);
    }
}

void
input_update(CInputState *state)
{
    MemoryCopyStruct(&state->keyboard_previous, &state->keyboard_current,
                     CKeyboardState);
    MemoryCopyStruct(&state->mouse_previous, &state->mouse_current,
                     CMouseState);

    state->mouse_current.wheel = 0;
}

b8
input_button_pressed(CInputState *state, u32 button)
{
    return state->mouse_previous.buttons[button]
           && state->mouse_current.buttons[button];
}

b8
input_button_down(CInputState *state, u32 button)
{
    return !state->mouse_previous.buttons[button]
           && state->mouse_current.buttons[button];
}

b8
input_button_up(CInputState *state, u32 button)
{
    return state->mouse_previous.buttons[button]
           && !state->mouse_current.buttons[button];
}

b8
input_key_pressed(CInputState *state, u32 key)
{
    return state->keyboard_previous.keys[key]
           && state->keyboard_current.keys[key];
}

b8
input_key_down(CInputState *state, u32 key)
{
    return !state->keyboard_previous.keys[key]
           && state->keyboard_current.keys[key];
}

b8
input_key_up(CInputState *state, u32 key)
{
    return state->keyboard_previous.keys[key]
           && !state->keyboard_current.keys[key];
}

void
input_mouse_position_get(CInputState *state, i32 *x, i32 *y)
{
    *x = state->mouse_current.x;
    *y = state->mouse_current.y;
}

void
input_mouse_wheel_get(CInputState *state, i32 *delta)
{
    *delta = state->mouse_current.wheel;
}
