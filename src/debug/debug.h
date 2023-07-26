#pragma once

#include "base/defines.h"

#define PROFILER_FUNCTIONS_MAX 1000

typedef struct CDebugProfilerFunc
{
    const char *name;
    u64         cycle_count;
    u64         hit_count;
} CDebugProfilerFunc;

typedef struct CDebugState
{
    CDebugProfilerFunc functions[PROFILER_FUNCTIONS_MAX];
    u64                function_count;
} CDebugState;

API void debug_startup(void);
API void debug_shutdown(void);
API void debug_update(void);

API void debug_profiler_startup(void);
API void debug_profiler_shutdown(void);
API void debug_profiler_handle(void);

API CDebugProfilerFunc *debug_profiler_function_add(const char *func_name);
API CDebugProfilerFunc *debug_profiler_function_find(const char *func_name);

API void *_debug_profiler_timed_block_begin(const char *func_name);
API void  _debug_profiler_timed_block_end(void *counter_ptr, u64 cycle_count);

#define PROFILER_BEGIN(NAME)                                                  \
    void *current_counter_##NAME = _debug_profiler_timed_block_begin(#NAME);  \
    u64   start_##NAME           = core_perf_counter();

#define PROFILER_END(NAME)                                                    \
    u64 end_##NAME = core_perf_counter();                                     \
    _debug_profiler_timed_block_end(current_counter_##NAME,                   \
                                    end_##NAME - start_##NAME);
