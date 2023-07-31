#pragma once

#include "ccb/base/defines.h"
#include "ccb/core/logger.h"
#include "ccb/memory/arena.h"

typedef struct CString
{
    char *data;
    u64   size;
} CString;

INLINE CString
str_lit(const char *c)
{
    CString result;
    result.data = (char *)c;
    result.size = strlen(c);
    return result;
}

INLINE b8
str_eq(const CString left, const CString right)
{
    b8 result = !strcmp(left.data, right.data);
    return result;
}

INLINE void
str_copy(CMemoryArena *arena, CString *dest, const CString *src)
{
    dest->data = PushArrayZero(arena, char, src->size);
    dest->size = src->size;
    MemoryCopyArray(dest->data, src->data, char, src->size);
}

API CString str_replace(CMemoryArena *arena, const CString replace,
                        const CString a, const CString b);

API CString str_path_fix(CMemoryArena *arena, const CString path);
API CString str_path_root(const CString path);
API CString str_path_root_name(const CString path);
API CString str_path_directory(const CString path);
API CString str_path_parent(const CString path);
API CString str_path_relative(const CString path);

API CString str_file_name(const CString file_path);
API CString str_file_name_remove(const CString file_path);
API CString str_file_name_replace(const CString file_path);
API CString str_file_extension(const CString file_path);
API CString str_file_extension_remove(const CString file_path);
API CString str_file_extension_replace(const CString file_path);
