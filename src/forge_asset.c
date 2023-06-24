#include "forge_asset.h"
#include "forge_gfx.h"
#include "forge_log.h"
#include "forge_window.h"

#include "forge_asset_internal.c"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void asset_init(void) {
    i32 img_flags = IMG_INIT_PNG;
    if ((IMG_Init(img_flags) & img_flags) != img_flags) {
        printf("Failed to initialize SDL_image: %s\n", IMG_GetError());
    }
}

void asset_destroy(void) { IMG_Quit(); }

Image *asset_load_image(const char *file_path) {
    Image *result = calloc(sizeof(Image), 1);

    result->surface = IMG_Load(file_path);
    if (result == NULL) {
        printf("Failed to load image: %s\n", IMG_GetError());
        return result;
    }

    WindowState *window = gfx_get_window();
    result->texture =
        SDL_CreateTextureFromSurface(window->renderer, result->surface);

    return result;
}

void asset_unload_image(Image *image) { SDL_FreeSurface(image->surface); }

void *asset_load_rw_data(const char *file_path) {
    u64 size = 0;
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("Failed to open file: %s\n", file_path);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    void *buffer = calloc(size, 1);
    if (buffer == NULL) {
        printf("Failed to allocate memory for buffer\n");
        fclose(file);
        return NULL;
    }

    size_t result = fread(buffer, 1, size, file);
    if (result != size) {
        printf("Failed to read file: %s\n", file_path);
        free(buffer);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return buffer;
}

Vector2 asset_image_get_size(Image *image) {
  Vector2 result;
  result.width = image->surface->w;
  result.height = image->surface->h;
  return result;
}

