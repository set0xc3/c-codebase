#include "core/core.h"

void
debug_startup(CCoreState *core)
{
    debug_profiler_startup(core);
}

void
debug_shutdown(CCoreState *core)
{
    debug_profiler_shutdown(core);
    debug_memory_handle(core);
}

void
debug_update(CCoreState *core)
{
    debug_profiler_handle(core);
}
