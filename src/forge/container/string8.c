#include "forge/container/string.h"
#include "forge/logger/logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

String8
str8(const char *c)
{
    String8 result;
    result.str = (uint8_t *)c;
    result.size = strlen(c);
    return result;
}

char *
str8_c(const String8 string)
{
    char *resutl = (char *)string.str;
    return resutl;
}

String8 *
str8_alloc(const String8 string)
{
    uint64_t size = (sizeof(String8) + sizeof(uint8_t) * string.size) + 1;
    String8 *result = (String8 *)malloc(size);
    result->str = (uint8_t *)(result + 1);
    result->size = string.size;
    memcpy(result->str, string.str, string.size + 1);
    return result;
}

void
str8_realloc(String8 *result, const uint64_t new_size)
{
    uint64_t size = (sizeof(String8) + sizeof(uint8_t) * new_size) + 1;
    result = (String8 *)realloc(result, size);
    if (result == NULL)
    {
        log_error("Failed to allocate string\n");
        return;
    }

    result->str = (uint8_t *)(result + 1);
    result->size = new_size;
    result->str[result->size] = '\0';
}

void
str8_free(String8 *string)
{
    free(string);
}

void
str8_name(String8 *result, const String8 file_path)
{
    const char *c = strrchr((const char *)result->str, '/');
    if (c != NULL)
    {
        uint64_t offset = (uint64_t)(c - (char *)result->str) + 1;
        if (offset > 0)
        {
            uint64_t new_size = result->size - offset;
            str8_realloc(result, new_size);

            memmove(result->str, result->str + offset, result->size);
        }
    }
    else
    {
        log_error("File path does not contain '/'\n");
    }
}

void
str8_ext(String8 *result, const String8 file_path)
{
    const char *c = strrchr((const char *)result->str, '.');
    if (c != NULL)
    {
        uint64_t offset = (uint64_t)(c - (const char *)result->str) + 1;
        if (offset > 0)
        {
            uint64_t new_size = result->size - offset;
            str8_realloc(result, new_size);

            memmove(result->str, result->str + offset, result->size);
        }
    }
    else
    {
        log_error("File path does not contain '.'\n");
    }
}

void
str8_dir(String8 *result, const String8 file_path)
{
    const char *c = strrchr((const char *)result->str, '/');
    if (c != NULL)
    {
        uint64_t offset = (uint64_t)(c - (const char *)result->str);
        if (offset > 0)
        {
            uint64_t new_size = offset;
            str8_realloc(result, new_size);
        }
    }
    else
    {
        log_error("File path does not contain '/'\n");
    }
}

void
str8_name_no_ext(String8 *result, const String8 file_path)
{
    str8_name(result, file_path);
    str8_remove_ext(result, file_path);
}

void
str8_remove_ext(String8 *result, const String8 file_path)
{
    const char *c = strrchr((const char *)result->str, '.');
    if (c != NULL)
    {
        uint64_t offset = (uint64_t)(c - (const char *)result->str);
        if (offset > 0)
        {
            uint64_t new_size = offset;
            str8_realloc(result, new_size);
        }
    }
    else
    {
        log_error("File path does not contain '.'\n");
    }
}

bool
str8_eq(const String8 left, const String8 right)
{
    bool result = !strcmp(str8_c(left), str8_c(right));
    return result;
}
