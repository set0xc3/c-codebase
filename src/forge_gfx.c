#include "forge_gfx.h"
#include "forge.h"
#include "forge_base_types.h"
#include "forge_log.h"
#include "forge_memory_arena.h"
#include "forge_window.h"

#include <stdlib.h>

struct GFXState {
    MemoryArena *arena;
    InputState *input;
    WindowState *window;
};

GFXState *gfx_init(void) {
    MemoryArena *arena = arena_create(Megabytes(64));
    GFXState *result = arena_push_zero(arena, sizeof(GFXState));

    result->arena = arena;
    result->input = arena_push_zero(result->arena, sizeof(InputState));
    result->window = arena_push_zero(result->arena, sizeof(WindowState));

    forge_init();

    result->window = window_open("Window", 0, 0, 800, 600);

    return result;
}

void gfx_destroy(void) { forge_destroy(); }

bool gfx_update(GFXState *gfx) {
    input_update(gfx->input);

    WindowEvent event = {0};
    window_poll_event(&event);

    switch (event.kind) {
    case WINDOW_EVENT_KIND_QUIT:
        window_close(gfx->window);
        log_info("Shutdown...\n");
        return false;
    case WINDOW_EVENT_KIND_WINDOW_CLOSED: {
    } break;
    case WINDOW_EVENT_KIND_MOUSE_BUTTON:
        input_button_callback(gfx->input, event.code, event.state);
        break;
    case WINDOW_EVENT_KIND_KEY:
        input_key_callback(gfx->input, event.code, event.state);
        break;
    case WINDOW_EVENT_KIND_MOUSE_MOTION:
        input_mouse_position_callback(gfx->input,
                                      v2((f32)event.xpos, (f32)event.ypos));
        break;
    case WINDOW_EVENT_KIND_SCROLL_MOTION:
        input_scroll_callback(gfx->input,
                              v2((f32)event.xwheel, (f32)event.ywheel));
        break;
    default:
        break;
    }

    return true;
}

void gfx_begin(GFXState *gfx) {
    SDL_SetRenderDrawColor(gfx->window->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gfx->window->renderer);
}

void gfx_draw_rect(GFXState *gfx, Vector3 position, Vector3 size,
                   Vector4 color) {
    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = size.x;
    rect.h = size.y;
    SDL_SetRenderDrawColor(gfx->window->renderer, color.r, color.g, color.b,
                           color.a);
    SDL_RenderDrawRect(gfx->window->renderer, &rect);
}

void gfx_draw_fill_rect(GFXState *gfx, Vector3 position, Vector2 size,
                        Vector4 color) {
    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = size.x;
    rect.h = size.y;
    SDL_SetRenderDrawColor(gfx->window->renderer, color.r, color.g, color.b,
                           color.a);
    SDL_RenderFillRect(gfx->window->renderer, &rect);
}

void gfx_draw_sprite(GFXState *gfx, SDL_Texture *texture, Vector3 position,
                     Vector2 size, Vector4 color) {

    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = size.x;
    rect.h = size.y;

    if (texture == NULL) {
        gfx_draw_fill_rect(gfx, position, size,
                           v4(255.0f, 0.0f, 255.0f, 255.0f));
        return;
    }

    SDL_SetRenderTarget(gfx->window->renderer, texture);
    SDL_RenderCopy(gfx->window->renderer, texture, NULL, &rect);
    SDL_SetRenderTarget(gfx->window->renderer, NULL);
}

void gfx_draw_line(GFXState *gfx, Vector3 a, Vector3 b, Vector4 color) {
    SDL_SetRenderDrawColor(gfx->window->renderer, color.r, color.g, color.b,
                           color.a);
    SDL_RenderDrawLine(gfx->window->renderer, a.x, a.y, b.x, b.y);
}

void gfx_end(GFXState *gfx) { SDL_RenderPresent(gfx->window->renderer); }

InputState *gfx_get_input(GFXState *gfx) { return gfx->input; }

WindowState *gfx_get_window(GFXState *gfx) { return gfx->window; }
