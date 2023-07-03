#ifndef FORGE_GRAPHICS_WINDOW_H
#define FORGE_GRAPHICS_WINDOW_H

#include "forge/base/base.h"
#include "forge/platform/platform.h"

#include <SDL2/SDL.h>

typedef enum WindowEventKind
{
    WINDOW_EVENT_KIND_NULL,
    WINDOW_EVENT_KIND_QUIT,
    WINDOW_EVENT_KIND_WINDOW_CLOSED,
    WINDOW_EVENT_KIND_WINDOW_RESIZED,
    WINDOW_EVENT_KIND_MOUSE_BUTTON,
    WINDOW_EVENT_KIND_MOUSE_MOTION,
    WINDOW_EVENT_KIND_SCROLL_MOTION,
    WINDOW_EVENT_KIND_KEY,
    WINDOW_EVENT_KIND_COUNT,
} WindowEventKind;

typedef struct WindowEvent WindowEvent;
typedef struct WindowState WindowState;

EXPORT_LIB WindowState *window_open(const char *title, i32 xpos, i32 ypos,
                                    i32 width, i32 height);
EXPORT_LIB void         window_close(WindowState *window);
EXPORT_LIB void         window_event_handler(WindowEvent *return_event);

#endif // FORGE_GRAPHICS_WINDOW_H
