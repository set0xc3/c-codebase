#ifndef FORGE_AUDIO_H
#define FORGE_AUDIO_H

typedef struct Audio_State Audio_State;

extern Audio_State *audio_load(const char *path);
extern void audio_unload(Audio_State *audio);
extern void audio_play(Audio_State *audio);
extern void audio_stop(Audio_State *audio);

#endif // FORGE_AUDIO_H
