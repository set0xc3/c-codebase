#pragma once

#include "base/defines.h"

typedef struct CUUID
{
    char value[36];
} CUUID;

void  uuid_seed(u64 seed);
CUUID uuid_generate(void);
