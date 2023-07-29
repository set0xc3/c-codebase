#pragma once

#include "base/defines.h"

typedef struct CLibrary
{
    b8    is_valid;
    void *handle;

    void (*startup)(void);
    void (*update)(f32 dt);
    void (*shutdown)(void);
} CLibrary;

API b8 os_startup(void);
API b8 os_shutdown(void);

API b8   os_poll_event(void);
API void os_sleep(u32 ms);
API u64  os_perf_counter(void);
API u64  os_perf_frequency(void);

API CLibrary os_library_load(const char *path);
API void     os_library_unload(CLibrary *library);
API void    *os_library_load_function(CLibrary *library, const char *name);
