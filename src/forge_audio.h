#ifndef FORGE_AUDIO_H
#define FORGE_AUDIO_H

#include "forge_platform_types.h"

typedef enum Audio_Support {
    AUDIO_SUPPORT_WAVE,
    AUDIO_SUPPORT_COUNT
} Audio_Support;

typedef struct Audio_State Audio_State;

EXPORT_LIB void audio_init(void);
EXPORT_LIB Audio_State *audio_load(const char *file_path);
EXPORT_LIB void audio_unload(Audio_State *audio_state);
EXPORT_LIB void audio_play(Audio_State *audio_state);
EXPORT_LIB void audio_stop(Audio_State *audio_state);

#endif // FORGE_AUDIO_H
