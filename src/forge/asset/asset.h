#ifndef FORGE_ASSET_H
#define FORGE_ASSET_H

#include "forge/container/vector.h"
#include "forge/platform/platform.h"

typedef struct Image      Image;
typedef struct AssetState AssetState;

EXPORT_LIB void   asset_init(void);
EXPORT_LIB void   asset_destroy(void);
EXPORT_LIB void  *asset_file_rw_data_load(const char *file_path);
EXPORT_LIB Image *asset_image_load(const char *file_path);
EXPORT_LIB void   asset_image_unload(Image *image);
EXPORT_LIB V2F    asset_image_size_get(Image *image);

#endif // FORGE_ASSET_H
