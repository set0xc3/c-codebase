#include "ccb/base/defines.h"
#include "ccb/container/string.h"
#include "ccb/core/logger.h"
#include "ccb/core/uuid.h"
#include "ccb/memory/arena.h"
#include "ccb/os/os.h"
#include "ccb/renderer/camera.h"
#include "ccb/window/window.h"

global_variable b8       is_running  = true;
global_variable CWindow *root_window = NULL;
global_variable CCamera *camera      = NULL;

int
main(int argc, char *argv[])
{
    printf("\n");

    CMemoryArena *arena = arena_create(Gigabytes(1));

    CString path
        = str_lit("/home/duck/hole/dev/c-codebase/sandbox/src/sandbox/main.c");
    // = str_lit("main.c");

    path = str_find_last(&path, '/', -1);
    LOG_DEBUG("path: %s:%d\n", path.data, path.size);
    path = str_find_last(&path, '/', 3);
    LOG_DEBUG("path: %s:%d\n", path.data, path.size);
    path = str_find_last(&path, '/', 2);
    LOG_DEBUG("path: %s:%d\n", path.data, path.size);
    path = str_find_last(&path, '/', 1);
    LOG_DEBUG("path: %s:%d\n", path.data, path.size);
    path = str_find_last(&path, '/', 0);
    LOG_DEBUG("path: %s:%d\n", path.data, path.size);

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

    printf("\n");

    return 0;
}
