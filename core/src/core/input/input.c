#include "core/core.h"

void
input_startup(CCoreState *core)
{
    core->input = MemoryAllocStruct(CInputState);
    MemoryZeroStruct(core->input, CInputState);
}

void
input_shutdown(CCoreState *core)
{
    MemoryFree(core->input);
}

void
input_button_process(CCoreState *core, u32 button, b8 pressed)
{
    if (core->input->mouse_current.buttons[button] != pressed)
    {
        // log_info("button: %i, %i\n", button, pressed);

        core->input->mouse_current.buttons[button] = pressed;

        CEvent event      = { 0 };
        event.data.u32[0] = button;
        event_fire(
            core, pressed ? EventCode_ButtonPressed : EventCode_ButtonReleased,
            event);
    }
}

void
input_key_process(CCoreState *core, u32 key, b8 pressed)
{
    if (core->input->keyboard_current.keys[key] != pressed)
    {
        // log_info("key: %i, %i\n", key, pressed);

        core->input->keyboard_current.keys[key] = pressed;

        CEvent event      = { 0 };
        event.data.u32[0] = key;
        event_fire(core,
                   pressed ? EventCode_KeyPressed : EventCode_KeyReleased,
                   event);
    }
}

void
input_mouse_motion_process(CCoreState *core, i32 x, i32 y)
{
    if (core->input->mouse_current.x != x || core->input->mouse_current.y != y)
    {
        // log_info("mouse.position: (%i, %i)\n", x, y);

        core->input->mouse_current.x = x;
        core->input->mouse_current.y = y;

        CEvent event      = { 0 };
        event.data.u32[0] = x;
        event.data.u32[1] = y;
        event_fire(core, EventCode_MouseMotion, event);
    }
}

void
input_mouse_scroll_process(CCoreState *core, i32 delta)
{
    if (core->input->mouse_current.wheel != delta)
    {
        // log_info("mouse.scroll: (%i)\n", delta);

        core->input->mouse_current.wheel = delta;

        CEvent event      = { 0 };
        event.data.u32[0] = delta;
        event_fire(core, EventCode_MouseWheel, event);
    }
}

void
input_update(CCoreState *core)
{
    memcpy(&core->input->keyboard_previous, &core->input->keyboard_current,
           sizeof(CKeyboardState));
    memcpy(&core->input->mouse_previous, &core->input->mouse_current,
           sizeof(CMouseState));

    core->input->mouse_current.wheel = 0;
}

b8
input_button_pressed(CCoreState *core, u32 button)
{
    return core->input->mouse_previous.buttons[button]
           && core->input->mouse_current.buttons[button];
}

b8
input_button_down(CCoreState *core, u32 button)
{
    return !core->input->mouse_previous.buttons[button]
           && core->input->mouse_current.buttons[button];
}

b8
input_button_up(CCoreState *core, u32 button)
{
    return core->input->mouse_previous.buttons[button]
           && !core->input->mouse_current.buttons[button];
}

b8
input_key_pressed(CCoreState *core, u32 key)
{
    return core->input->keyboard_previous.keys[key]
           && core->input->keyboard_current.keys[key];
}

b8
input_key_down(CCoreState *core, u32 key)
{
    return !core->input->keyboard_previous.keys[key]
           && core->input->keyboard_current.keys[key];
}

b8
input_key_up(CCoreState *core, u32 key)
{
    return core->input->keyboard_previous.keys[key]
           && !core->input->keyboard_current.keys[key];
}

void
input_mouse_position_get(CCoreState *core, i32 *x, i32 *y)
{
    *x = core->input->mouse_current.x;
    *y = core->input->mouse_current.y;
}

void
input_mouse_wheel_get(CCoreState *core, i32 *delta)
{
    *delta = core->input->mouse_current.wheel;
}
