#include "forge_gfx.h"
#include "forge_input.h"
#include "forge_log.h"
#include "forge_window.h"

#include <stdlib.h>

global_variable InputState *input;
global_variable WindowState *root_window;

EXPORT_LIB void gfx_init(void) {
    input = malloc(sizeof(InputState));
    root_window = window_open("Window", 0, 0, 800, 600);
}

EXPORT_LIB bool gfx_update(void) {
    input_update(input);

    WindowEvent event = {0};
    window_poll_event(&event);

    switch (event.kind) {
    case WINDOW_EVENT_KIND_QUIT:
        window_close(root_window);
        log_info("Shutdown...\n");
        return false;
    case WINDOW_EVENT_KIND_WINDOW_CLOSED: {
    } break;
    case WINDOW_EVENT_KIND_MOUSE_BUTTON:
        input_button_callback(input, event.code, event.state);
        break;
    case WINDOW_EVENT_KIND_KEY:
        input_key_callback(input, event.code, event.state);
        break;
    case WINDOW_EVENT_KIND_MOUSE_MOTION:
        input_mouse_pos_callback(input, event.xpos, event.ypos);
        break;
    case WINDOW_EVENT_KIND_SCROLL_MOTION:
        input_scroll_callback(input, event.xwheel, event.ywheel);
        break;
    default:
        break;
    }

    return true;
}
