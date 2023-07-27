#include "window/window.h"
#include "base/defines.h"
#include "core/logger.h"

global_variable CWindow window;

void
test_window_open()
{
    if (!window_open(&window, "", 0, 0, 0, 0))
    {
        LOG_ERROR("[TEST] Failed window_open\n");
    }
}

void
test_window_close()
{
    if (!window_close(&window))
    {
        LOG_ERROR("[TEST] Failed window_close\n");
    }
}
