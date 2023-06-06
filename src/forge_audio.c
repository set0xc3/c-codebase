#include "forge_audio.h"

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum Audio_Support { WAVE } Audio_Support;

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
};

Audio_State *audio_load(const char *path) {
    Audio_State *result = NULL;
    return result;
}

void audio_unload(Audio_State *audio) {}

void audio_play(Audio_State *audio) {}

void audio_stop(Audio_State *audio) {}
