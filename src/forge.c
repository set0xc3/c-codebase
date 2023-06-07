#include "forge.h"
#include "forge_log.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

void forge_init() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        log_error("SDL could not initialize: %s\n", SDL_GetError());
    }
}

void forge_sleep(uint32_t ms) {
    SDL_Delay(ms);
}
