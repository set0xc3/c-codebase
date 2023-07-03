#include "forge/forge.h"
#include "forge/logger/logger.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

void
forge_init(void)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        log_error("SDL could not initialize: %s\n", SDL_GetError());
    }
}

void
forge_destroy(void)
{
    SDL_Quit();
}

void
forge_sleep(u32 ms)
{
    SDL_Delay(ms);
}

u64
forge_perf_counter(void)
{
    return SDL_GetPerformanceCounter();
}

u64
forge_perf_frequency(void)
{
    return SDL_GetPerformanceFrequency();
}
