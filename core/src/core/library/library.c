#include "core/core.h"

#include <SDL2/SDL.h>

CLibrary
library_load(CCoreState *core, const char *path)
{
    CLibrary result = { 0 };

    char *dot      = ".";
    u64   dot_size = strlen(dot);

    u64      size     = strlen(path) + strlen(LIBRARY_EXTENSION) + dot_size;
    CString8 path_ext = { (u8 *)alloca(size), size };
    strncpy((char *)path_ext.str, path, path_ext.size);

    strncat((char *)path_ext.str, dot, path_ext.size);
    strncat((char *)path_ext.str, LIBRARY_EXTENSION, path_ext.size);

    result.handle = SDL_LoadObject((const char *)path_ext.str);
    if (result.handle == NULL)
    {
        LOG_ERROR("[SDL] %s\n", SDL_GetError());
    }

    result.is_valid = true;

    return result;
}

void
library_unload(CCoreState *core, CLibrary *library)
{
    SDL_UnloadObject(library->handle);
    MemoryFree(library);
}

void *
library_load_function(CCoreState *core, CLibrary *library, const char *name)
{
    return SDL_LoadFunction(library->handle, name);
}
