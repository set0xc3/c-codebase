#include "forge_string.h"
#include "forge_log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

String8 str8(const char *str) {
    String8 result;
    result.str = (uint8_t *)str;
    result.size = strlen(str);
    return result;
}

String8 str8_alloc(const String8 *string) {
    String8 result;
    result.str = (uint8_t *)malloc(string->size + 1);
    result.size = string->size;
    memcpy(result.str, string->str, string->size + 1);
    return result;
}

void str8_free(String8 *string) { free(string->str); }

void str8_name(String8 *result, const String8 file_path) {
    const char *c = strrchr((const char *)result->str, '/');
    if (c != NULL) {
        size_t pos = (size_t)(c - (const char *)result->str) + 1;
        uint64_t new_size = result->size - pos;
        if (pos == 0) {
            return;
        } else if (pos > 0) {
            char *new_str = (char *)realloc(result->str, new_size + 1);
            if (new_str == NULL) {
                log_error("Failed to allocate string\n");
                return;
            }

            result->str = (uint8_t *)new_str;
            result->size = new_size;
            memmove(result->str, result->str + pos, result->size + 1);

            result->str[result->size] = '\0';
        }
    } else {
        log_error("File path does not contain '/'\n");
    }
}

void str8_ext(String8 *result, const String8 file_path) {
    const char *c = strrchr((const char *)result->str, '.');
    if (c != NULL) {
        size_t pos = (size_t)(c - (const char *)result->str) + 1;
        uint64_t new_size = result->size - pos;
        if (pos == 0) {
            return;
        } else if (pos > 0) {
            char *new_str = (char *)realloc(result->str, new_size + 1);
            if (new_str == NULL) {
                log_error("Failed to allocate string\n");
                return;
            }

            result->str = (uint8_t *)new_str;
            result->size = new_size;
            memmove(result->str, result->str + pos, result->size + 1);

            result->str[result->size] = '\0';
        }
    } else {
        log_error("File path does not contain '.'\n");
    }
}

void str8_dir(String8 *result, const String8 file_path) {
    const char *c = strrchr((const char *)result->str, '/');
    if (c != NULL) {
        size_t pos = (size_t)(c - (const char *)result->str);
        uint64_t new_size = pos;
        if (pos == 0) {
            return;
        } else if (pos > 0) {
            char *new_str = (char *)realloc(result->str, new_size + 1);
            if (new_str == NULL) {
                log_error("Failed to allocate string\n");
                return;
            }

            result->str = (uint8_t *)new_str;
            result->size = new_size;
            result->str[result->size] = '\0';
        }
    } else {
        log_error("File path does not contain '/'\n");
    }
}

void str8_name_no_ext(String8 *result, const String8 file_path) {
    str8_name(result, file_path);
    str8_remove_ext(result, file_path);
}

void str8_remove_ext(String8 *result, const String8 file_path) {
    const char *c = strrchr((const char *)result->str, '.');
    if (c != NULL) {
        size_t pos = (size_t)(c - (const char *)result->str);
        uint64_t new_size = pos;
        if (pos == 0) {
            return;
        } else if (pos > 0) {
            char *new_str = (char *)realloc(result->str, new_size + 1);
            if (new_str == NULL) {
                log_error("Failed to allocate string\n");
                return;
            }

            result->str = (uint8_t *)new_str;
            result->size = new_size;
            result->str[result->size] = '\0';
        }
    } else {
        log_error("File path does not contain '.'\n");
    }
}
