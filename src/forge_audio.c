#include "forge_audio.h"
#include "forge_base_types.h"
#include "forge_log.h"
#include "forge_string.h"

#include <SDL2/SDL_mixer.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

global_variable const char *audio_ext_list[AUDIO_SUPPORT_COUNT] = {
    [AUDIO_SUPPORT_WAVE] = "wav",
};

typedef struct Wave_Header {
    unsigned char riff[4];             // RIFF string
    unsigned int overall_size;         // overall size of file in bytes
    unsigned char wave[4];             // WAVE string
    unsigned char fmt_chunk_marker[4]; // fmt string with trailing null char
    unsigned int length_of_fmt;        // length of the format data
    unsigned int format_type; // format type. 1-PCM, 3- IEEE float, 6 - 8bit A
                              // law, 7 - 8bit mu law
    unsigned int channels;    // no.of channels
    unsigned int sample_rate; // sampling rate (blocks per second)
    unsigned int byterate;    // SampleRate * NumChannels * BitsPerSample/8
    unsigned int block_align; // NumChannels * BitsPerSample/8
    unsigned int bits_per_sample; // bits per sample, 8- 8bits, 16- 16 bits etc
    unsigned char data_chunk_header[4]; // DATA string or FLLR string
    unsigned int data_size; // NumSamples * NumChannels * BitsPerSample/8 - size
                            // of the next chunk that will be read
} Wave_Header;

struct Audio_State {
    bool is_sound_enabled;
    Mix_Music *music;
};

void audio_init(void) {}

Audio_State *audio_load(const char *file_path) {
    Audio_State *result = malloc(sizeof(Audio_State));
    memset(result, 0, sizeof(Audio_State));

    String8 *file_ext = str8_alloc(str8(file_path));
    str8_ext(file_ext, str8(file_path));

    bool is_found_ext = false;
    for (size_t i = 0; i < AUDIO_SUPPORT_COUNT; i += 1) {
        if (str8_eq(*file_ext, str8(audio_ext_list[i]))) {
            is_found_ext = true;
            break;
        }
    }

    if (is_found_ext) {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            log_error("SDL_mixer could not initialize: %s\n", Mix_GetError());
        }

        result->music = Mix_LoadMUS(file_path);

    } else {
        log_warning("Format not supported: %s\n", str8_c(*file_ext));
    }

    str8_free(file_ext);

    return result;
}

void audio_unload(Audio_State *audio_state) {
    Mix_FreeMusic(audio_state->music);
    free(audio_state);
}

void audio_play(Audio_State *audio_state) {
    if (!audio_state->is_sound_enabled) {
        Mix_PlayMusic(audio_state->music, -1);
        audio_state->is_sound_enabled = true;
    }
}

void audio_stop(Audio_State *audio_state) {}
