#ifndef FORGE_STRING_H
#define FORGE_STRING_H

#include "forge_platform_types.h"

#include <stdbool.h>
#include <stdint.h>

typedef struct String8 {
    uint8_t *str;
    uint64_t size;
} String8;

EXPORT_LIB String8 str8(const char *c);
EXPORT_LIB char *str8_c(const String8 string);
EXPORT_LIB String8 *str8_alloc(const String8 string);
EXPORT_LIB void str8_realloc(String8 *result, const uint64_t new_size);
EXPORT_LIB void str8_free(String8 *string);
EXPORT_LIB void str8_name(String8 *result, const String8 file_path);
EXPORT_LIB void str8_ext(String8 *result, const String8 file_path);
EXPORT_LIB void str8_dir(String8 *result, const String8 file_path);
EXPORT_LIB void str8_name_no_ext(String8 *result, const String8 file_path);
EXPORT_LIB void str8_remove_ext(String8 *result, const String8 file_path);
EXPORT_LIB bool str8_eq(const String8 left, const String8 right);

#endif // FORGE_STRING_H
