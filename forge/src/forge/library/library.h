#ifndef FORGE_LIBRARY_H
#define FORGE_LIBRARY_H

#include "forge/base/base.h"
#include "forge/platform/platform.h"

typedef struct IInterface IInterface;
typedef struct ILib       ILib;

EXPORT_LIB ILib *library_load(char *path, IInterface *interface);
EXPORT_LIB ILib *library_unload(ILib *lib, b32 interface);

#endif // FORGE_LIBRARY_H
