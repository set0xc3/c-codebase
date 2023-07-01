#ifndef FORGE_AUDIO_H
#define FORGE_AUDIO_H

#include "forge/platform/platform.h"

#include <stdbool.h>

typedef struct AudioState AudioState;

EXPORT_LIB void        audio_init(void);
EXPORT_LIB AudioState *audio_load(const char *file_path);
EXPORT_LIB void        audio_unload(AudioState *audio_state);
EXPORT_LIB void        audio_play(AudioState *audio_state, bool loop);
EXPORT_LIB void        audio_stop(AudioState *audio_state);

#endif // FORGE_AUDIO_H
