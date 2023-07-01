#ifndef FORGE_H
#define FORGE_H

#include "forge/base/base.h"
#include "forge/platform/platform.h"

EXPORT_LIB void forge_init(void);
EXPORT_LIB void forge_destroy(void);
EXPORT_LIB void forge_sleep(u32 ms);

#endif // FORGE_H
