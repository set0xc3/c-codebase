#include "core/core.h"

void
debug_profiler_startup(CCoreState *core)
{
}

void
debug_profiler_shutdown(CCoreState *core)
{
}

void
debug_profiler_handle(CCoreState *core)
{
    for (u64 i = 0; i < core->debug->function_count; i++)
    {
        CDebugProfilerFunc *function = &core->debug->functions[i];
        if (function->hit_count)
        {
            f64 dt = (f64)((f64)function->cycle_count
                           / (f64)core_perf_frequency(core));

            f64 dt_cyh
                = (f64)(((f64)function->cycle_count / function->hit_count)
                        / (f64)core_perf_frequency(core));

#if 0
            LOG_INFO("%s: %lu/cy : %lu/h : %lu/cy/h : %.3f/ms : %.3f/cy/ms\n",
                     function->name, function->cycle_count,
                     function->hit_count,
                     function->cycle_count / function->hit_count,
                     dt * 1000000.0f, dt_cyh * 1000000.0f);
#endif
            function->hit_count   = 0;
            function->cycle_count = 0;
        }
    }
}

CDebugProfilerFunc *
debug_profiler_function_add(CCoreState *core, const char *func_name)
{
    core->debug->functions[core->debug->function_count].name = func_name;
    core->debug->function_count++;

    return &core->debug->functions[core->debug->function_count - 1];
}

CDebugProfilerFunc *
debug_profiler_function_find(CCoreState *core, const char *func_name)
{
    for (u64 i = 0; i < core->debug->function_count; i++)
    {
        if (strcmp(func_name, core->debug->functions[i].name) == 0)
        {
            return &core->debug->functions[i];
        }
    }

    return debug_profiler_function_add(core, func_name);
}

void *
_debug_profiler_timed_block_begin(CCoreState *core, const char *func_name)
{
    return debug_profiler_function_find(core, func_name);
}

void
_debug_profiler_timed_block_end(void *counter_ptr, u64 cycle_count)
{
    CDebugProfilerFunc *counter = (CDebugProfilerFunc *)counter_ptr;
    counter->cycle_count += cycle_count;
    counter->hit_count++;
}
