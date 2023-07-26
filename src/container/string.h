#pragma once

#include "base/defines.h"
#include "memory/arena.h"

typedef struct CString8
{
    u8 *str;
    u64 size;
} CString8;

API CString8 str8(const char *c);
API b8       str8_eq(const CString8 left, const CString8 right);
API CString8 str8_concat(CMemoryArena *arena, CString8 dest,
                         CString8 src); // TODO
API CString8 str8_replace(CMemoryArena *arena, CString8 dest,
                          CString8 src); // TODO

#define str8_c(s) (const char *)s.str
