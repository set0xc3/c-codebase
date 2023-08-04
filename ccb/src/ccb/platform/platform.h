#pragma once

#include "ccb/base/defines.h"

typedef struct CLibrary
{
    b8    is_valid;
    void *handle;

    void (*startup)(void);
    void (*update)(f32 dt);
    void (*shutdown)(void);
} CLibrary;

API b8 platform_startup(void);
API b8 platform_shutdown(void);

API b8   platform_poll_event(void);
API void platform_delay(u32 ms);
API u64  platform_perf_counter(void);
API u64  platform_perf_frequency(void);

API CLibrary platform_library_load(const char *path);
API void     platform_library_unload(CLibrary *library);
API void *platform_library_load_function(CLibrary *library, const char *name);
