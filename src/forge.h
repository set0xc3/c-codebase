#ifndef FORGE_H
#define FORGE_H

#include "forge_platform_types.h"

#include <stdint.h>

EXPORT_LIB void forge_init(void);
EXPORT_LIB void forge_sleep(uint32_t ms);

#endif // FORGE_H
