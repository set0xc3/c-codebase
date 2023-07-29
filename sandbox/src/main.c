#include "base/defines.h"
#include "core/logger.h"
#include "memory/arena.h"
#include "os/os.h"
#include "renderer/camera.h"
#include "window/window.h"

global_variable b8       is_running  = true;
global_variable CWindow *root_window = NULL;
global_variable CCamera *camera      = NULL;

int
main(int argc, char *argv[])
{
    if (os_startup())
    {
        window_open(root_window, "RootWindow", 0, 0, 800, 600);

        while (is_running)
        {
            if (!os_poll_event())
            {
                is_running = false;
                window_close(root_window);
            }

            os_sleep(1);
        }
    }

    os_shutdown();

    return 0;
}
