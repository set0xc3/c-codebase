#include "forge_window.h"
#include "forge_log.h"

#include <SDL2/SDL.h>

#include <SDL2/SDL_events.h>
#include <stdbool.h>
#include <stdlib.h>

WindowState *window_open(const char *title, i32 xpos, i32 ypos, i32 width,
                         i32 height) {
    WindowState *result = malloc(sizeof(WindowState));
    result->title = title;
    result->rect.x = xpos;
    result->rect.y = ypos;
    result->rect.width = width;
    result->rect.height = height;

    u32 window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    result->handle =
        SDL_CreateWindow(result->title, result->rect.x, result->rect.y,
                         result->rect.width, result->rect.height, window_flags);
    if (!result->handle) {
        log_error("[SDL] Failed create window\n");
        return NULL;
    }

    return result;
}

void window_close(WindowState *window) {
    SDL_DestroyWindow(window->handle);
    free(window);
}

void window_poll_event(WindowEvent *return_event) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_WINDOWEVENT) {
            switch (event.window.event) {
            case SDL_WINDOWEVENT_CLOSE:
                return_event->handle = (u64 *)SDL_GetWindowFromID(event.window.windowID);
                return_event->kind = WINDOW_EVENT_KIND_WINDOW_CLOSED;
            }
        }

        switch (event.type) {
        case SDL_QUIT:
            return_event->kind = WINDOW_EVENT_KIND_QUIT;
            break;
        case SDL_MOUSEMOTION:
            return_event->kind = WINDOW_EVENT_KIND_MOUSE_MOTION;
            return_event->xpos = event.motion.x;
            return_event->ypos = event.motion.y;
            break;
        case SDL_MOUSEWHEEL:
            return_event->kind = WINDOW_EVENT_KIND_SCROLL_MOTION;
            return_event->xwheel = event.wheel.x;
            return_event->ywheel = event.wheel.y;
            break;
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP: {
            return_event->kind = WINDOW_EVENT_KIND_MOUSE_BUTTON;
            return_event->state =
                event.button.state == SDL_PRESSED ? true : false;
            switch (event.button.button) {
            case SDL_BUTTON_LEFT:
                return_event->code = MOUSE_BUTTON_LEFT;
                break;
            case SDL_BUTTON_MIDDLE:
                return_event->code = MOUSE_BUTTON_MIDDLE;
                break;
            case SDL_BUTTON_RIGHT:
                return_event->code = MOUSE_BUTTON_RIGHT;
                break;
            }
        } break;
        case SDL_KEYDOWN:
        case SDL_KEYUP: {
            return_event->kind = WINDOW_EVENT_KIND_KEY;
            return_event->state = event.key.state == SDL_PRESSED ? true : false;
            switch (event.key.keysym.sym) {
            case SDLK_w:
                return_event->code = KEY_CODE_W;
                break;
            case SDLK_s:
                return_event->code = KEY_CODE_S;
                break;
            case SDLK_a:
                return_event->code = KEY_CODE_A;
                break;
            case SDLK_d:
                return_event->code = KEY_CODE_D;
                break;
            case SDLK_q:
                return_event->code = KEY_CODE_Q;
                break;
            case SDLK_e:
                return_event->code = KEY_CODE_E;
                break;
            case SDLK_ESCAPE:
                return_event->code = KEY_CODE_ESCAPE;
                break;
            }
        } break;
        }
    }
}
