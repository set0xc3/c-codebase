#include "window/window.h"
#include "base/defines.h"
#include "core/logger.h"

void
test_window_open(CWindow *window)
{
    if (!window_open(window, "Window", 0, 0, 0, 0))
    {
        LOG_ERROR("[TEST] Failed window_open\n");
    }
}

void
test_window_close(CWindow *window)
{
    if (!window_close(window))
    {
        LOG_ERROR("[TEST] Failed window_close\n");
    }
}
