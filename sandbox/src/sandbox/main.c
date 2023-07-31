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

    CMemoryArena    *arena   = arena_create(Gigabytes(1));
    CMemoryArenaTemp scratch = arena_temp_scratch_get(arena);

    CString file_path = str_lit("game/src/../build/");
    CString fixed     = { 0 };

    fixed = str_path_fix(scratch.arena, file_path);

    // LOG_DEBUG("file_path: %s\n", fixed);

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
