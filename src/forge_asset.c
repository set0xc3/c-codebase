#include "forge_asset.h"
#include "forge_log.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture *asset_texture_load(GFXState *gfx, const char *file_path) {
    SDL_Texture *result = NULL;
    SDL_Surface *surface = SDL_LoadBMP(file_path);
	result = SDL_CreateTextureFromSurface(gfx->window->renderer, surface);
	SDL_FreeSurface(surface);

    if (result == NULL) {
        log_error("[FORGE] Failed load texture\n");
    }

    return result;
}

void asset_texture_unload(SDL_Texture *texture) {}
