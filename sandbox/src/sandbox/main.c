#include "ccb/base/defines.h"
#include "ccb/platform/platform.h"
#include "ccb/renderer/renderer.h"
#include "ccb/window/window.h"

global_variable b8 is_running = true;

global_variable CWindow        *root_window = NULL;
global_variable CRendererState *renderer    = NULL;

int
main(int argc, char *argv[])
{
    printf("\n");

    if (platform_startup())
    {
        root_window = window_open("RootWindow", 0, 0, 800, 600);
        renderer    = renderer_startup();

        while (is_running)
        {
            if (!platform_poll_event())
            {
                is_running = false;
            }

            renderer_begin_frame(renderer);
            renderer_end_frame(renderer);

            window_swap_buffer(root_window);

            platform_delay(1);
        }
    }

    window_close(root_window);
    platform_shutdown();

    printf("\n");

    return 0;
}
