#ifndef FORGE_STRING_H
#define FORGE_STRING_H

#include <stdint.h>

typedef struct String8 {
    uint8_t *str;
    uint64_t size;
} String8;

extern String8 str8(const char* str);
extern String8 str8_alloc(const String8 *string);
extern void str8_free(String8 *string);
extern void str8_name(String8 *result, const String8 file_path);
extern void str8_ext(String8 *result, const String8 file_path);
extern void str8_dir(String8 *result, const String8 file_path);
extern void str8_name_no_ext(String8 *result, const String8 file_path);
extern void str8_remove_ext(String8 *result, const String8 file_path);

#endif // FORGE_STRING_H
