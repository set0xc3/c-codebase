#ifndef FORGE_WINDOW_H
#define FORGE_WINDOW_H

#include "forge_base_types.h"
#include "forge_platform_types.h"

#include <stdint.h>

#include <SDL2/SDL.h>

typedef enum WindowEventKind {
    WINDOW_EVENT_KIND_NULL,
    WINDOW_EVENT_KIND_QUIT,
    WINDOW_EVENT_KIND_WINDOW_CLOSED,
    WINDOW_EVENT_KIND_MOUSE_BUTTON,
    WINDOW_EVENT_KIND_MOUSE_MOTION,
    WINDOW_EVENT_KIND_SCROLL_MOTION,
    WINDOW_EVENT_KIND_KEY,
    WINDOW_EVENT_KIND_COUNT,
} WindowEventKind;

typedef struct WindowEvent {
    u64 *handle;
    i32 kind;
    i32 code;
    i32 state;
    i32 xwheel, ywheel;
    i32 xpos, ypos;
} WindowEvent;

typedef struct WindowState {
    SDL_Window *handle;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    const char *title;
    struct {
        i32 x, y;
        i32 width, height;
    } rect;
} WindowState;

EXPORT_LIB WindowState *window_open(const char *title, i32 xpos, i32 ypos,
                                    i32 width, i32 height);
EXPORT_LIB void window_close(WindowState *window);
EXPORT_LIB void window_poll_event(WindowEvent *return_event);

#endif // FORGE_WINDOW_H
