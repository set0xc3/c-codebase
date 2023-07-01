#ifndef FORGE_ASSET_H
#define FORGE_ASSET_H

#include "forge/container/vector.h"
#include "forge/platform/platform.h"

typedef struct Image      Image;
typedef struct AssetState AssetState;

EXPORT_LIB void    asset_init(void);
EXPORT_LIB void    asset_destroy(void);
EXPORT_LIB Image  *asset_load_image(const char *file_path);
EXPORT_LIB void    asset_unload_image(Image *image);
EXPORT_LIB void   *asset_load_rw_data(const char *file_path);
EXPORT_LIB Vector2 asset_image_get_size(Image *image);

#endif // FORGE_ASSET_H
