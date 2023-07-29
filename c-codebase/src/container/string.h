#pragma once

#include "base/defines.h"

#define str8_c(s) (const char *)s.str

typedef struct CString8
{
    u8 *str;
    u64 size;
} CString8;

INLINE CString8
str8(const char *c)
{
    CString8 result;
    result.str  = (u8 *)c;
    result.size = strlen(c);
    return result;
}

INLINE b8
str8_eq(const CString8 left, const CString8 right)
{
    b8 result = !strcmp(str8_c(left), str8_c(right));
    return result;
}

// TODO
// API CString8 str8_concat(CMemoryArena *arena, CString8 dest,
//                          CString8 src); // TODO
// API CString8 str8_replace(CMemoryArena *arena, CString8 dest,
//                           CString8 src); // TODO
