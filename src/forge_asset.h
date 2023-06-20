#ifndef FORGE_ASSET_H
#define FORGE_ASSET_H

#include "forge_gfx.h"
#include "forge_platform_types.h"

#include <SDL2/SDL.h>

typedef struct AssetState AssetState;

EXPORT_LIB SDL_Texture *asset_texture_load(GFXState *gfx, const char *file_path);
EXPORT_LIB void asset_texture_unload(SDL_Texture *texture);

#endif // FORGE_ASSET_H
