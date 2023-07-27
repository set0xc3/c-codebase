#include <base/defines.h>
#include <core/logger.h>
#include <os/os.h>

#include <SDL2/SDL.h>

int
main(int argc, char *argv[])
{
    LOG_INFO("Example\n");

    os_startup();

    while (true)
    {
        // input_update();
        os_poll_event();
    }

    os_shutdown();

    return 0;
}
