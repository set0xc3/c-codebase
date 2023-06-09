#ifndef FORGE_H
#define FORGE_H

#include "forge_base_types.h"
#include "forge_platform_types.h"

#include <stdint.h>

EXPORT_LIB void forge_init(void);
EXPORT_LIB void forge_destroy(void);
EXPORT_LIB void forge_sleep(u32 ms);

#endif // FORGE_H
