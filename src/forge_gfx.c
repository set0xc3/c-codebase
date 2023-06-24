#include "forge_gfx.h"
#include "forge.h"
#include "forge_asset.h"
#include "forge_base_types.h"
#include "forge_input.h"
#include "forge_log.h"
#include "forge_memory_arena.h"
#include "forge_window.h"

#include "forge_asset_internal.c"

#include <stdlib.h>

struct GFXState {
    b32 is_quit;
    MemoryArena *arena;
    InputState *input;
    WindowState *window;
};

global_variable GFXState *g_gfx;

void gfx_init(void) {
    MemoryArena *arena = arena_create(Megabytes(64));
    g_gfx = arena_push_zero(arena, sizeof(GFXState));

    g_gfx->arena = arena;
    g_gfx->input = arena_push_zero(g_gfx->arena, sizeof(InputState));
    g_gfx->window = arena_push_zero(g_gfx->arena, sizeof(WindowState));

    forge_init();
    asset_init();
    input_init(g_gfx->input);

    g_gfx->window = window_open("Window", 0, 0, 1280, 720);
}

void gfx_destroy(void) { forge_destroy(); }

b32 gfx_update(void) {
    input_update();

    WindowEvent event = {0};
    window_poll_event(&event);

    switch (event.kind) {
    case WINDOW_EVENT_KIND_NULL:
        return false;
    case WINDOW_EVENT_KIND_QUIT:
        window_close(g_gfx->window);
        g_gfx->is_quit = true;
        break;
    case WINDOW_EVENT_KIND_WINDOW_CLOSED: {
    } break;
    case WINDOW_EVENT_KIND_MOUSE_BUTTON:
        input_button_callback(event.code, event.state);
        break;
    case WINDOW_EVENT_KIND_KEY:
        input_key_callback(event.code, event.state);
        break;
    case WINDOW_EVENT_KIND_MOUSE_MOTION:
        input_mouse_position_callback(v2((f32)event.xpos, (f32)event.ypos));
        break;
    case WINDOW_EVENT_KIND_SCROLL_MOTION:
        input_scroll_callback(v2((f32)event.xwheel, (f32)event.ywheel));
        break;
    case WINDOW_EVENT_KIND_WINDOW_RESIZED:
        g_gfx->window->rect.width = event.width;
        g_gfx->window->rect.height = event.height;
        break;
    default:
        break;
    }

    return true;
}

b32 gfx_is_quit(void) { return g_gfx->is_quit; }

WindowState *gfx_get_window(void) { return g_gfx->window; }

void gfx_window_set_position(Vector2 position) {
    g_gfx->window->rect.x = (i32)position.x;
    g_gfx->window->rect.y = (i32)position.y;
    SDL_SetWindowPosition(g_gfx->window->handle, position.x, position.y);
}

Vector2 gfx_window_get_position(void) {
    Vector2 result;
    result.x = (f32)g_gfx->window->rect.x;
    result.y = (f32)g_gfx->window->rect.y;
    return result;
}

void gfx_window_set_size(Vector2 size) {
    g_gfx->window->rect.width = (i32)size.x;
    g_gfx->window->rect.height = (i32)size.y;
    SDL_SetWindowSize(g_gfx->window->handle, size.x, size.y);
}

Vector2 gfx_window_get_size(void) {
    Vector2 result;
    result.x = (f32)g_gfx->window->rect.width;
    result.y = (f32)g_gfx->window->rect.height;
    return result;
}

void gfx_window_set_title(const char *title) {
    g_gfx->window->title = title;
    SDL_SetWindowTitle(g_gfx->window->handle, title);
}

const char *gfx_window_get_title(void) { return g_gfx->window->title; }

void gfx_begin(void) {
    SDL_SetRenderDrawColor(g_gfx->window->renderer, 0x0, 0x0, 0x0, 0x0);
    SDL_RenderClear(g_gfx->window->renderer);
}

void gfx_draw_rect(Vector3 position, Vector3 size, Vector4 color) {
    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = size.x;
    rect.h = size.y;
    SDL_SetRenderDrawColor(g_gfx->window->renderer, color.r, color.g, color.b,
                           color.a);
    SDL_RenderDrawRect(g_gfx->window->renderer, &rect);
}

void gfx_draw_fill_rect(Vector3 position, Vector2 size, Vector4 color) {
    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = size.x;
    rect.h = size.y;
    SDL_SetRenderDrawColor(g_gfx->window->renderer, color.r, color.g, color.b,
                           color.a);
    SDL_RenderFillRect(g_gfx->window->renderer, &rect);
}

void gfx_draw_image(Image *image, Vector3 position, Vector2 size,
                    Vector4 color) {

    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = size.x;
    rect.h = size.y;

    if (image->texture == NULL) {
        gfx_draw_fill_rect(position, size, v4(255.0f, 0.0f, 255.0f, 255.0f));
        return;
    }

    SDL_SetRenderTarget(g_gfx->window->renderer, image->texture);
    SDL_RenderCopy(g_gfx->window->renderer, image->texture, NULL, &rect);
    SDL_SetRenderTarget(g_gfx->window->renderer, NULL);
}

void gfx_draw_line(Vector3 a, Vector3 b, Vector4 color) {
    SDL_SetRenderDrawColor(g_gfx->window->renderer, color.r, color.g, color.b,
                           color.a);
    SDL_RenderDrawLine(g_gfx->window->renderer, a.x, a.y, b.x, b.y);
}

void gfx_end(void) { SDL_RenderPresent(g_gfx->window->renderer); }
