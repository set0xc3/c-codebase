#pragma once

#include "ccb/base/defines.h"
#include "ccb/core/logger.h"
#include "ccb/memory/arena.h"

typedef struct CString
{
    char *data;
    u64   size;
} CString;

typedef struct CStringNode
{
    struct CStringNode *next;
    CString             string;
} CStringNode;

typedef struct CStringList
{
    CStringNode *first;
    CStringNode *last;
    u64          node_count;
    u64          size;
} CStringList;

API CString str_lit(const char *c);
API CString str_alloc(CMemoryArena *arena, const u64 size);
API b8      str_eq(const CString left, const CString right);
API CString str_concast(CMemoryArena *arena, const CString *a,
                        const CString *b);
API CString str_prefix(const CString *str, const u64 size);
API u32     str_find_all(const CString *str, const char find);
API CString str_find_first(const CString *str, const char find,
                           const u64 offset);
API CString str_find_last(const CString *str, const char find,
                          const u64 offset);

// TODO: Formating
API CString str_pushfv(CMemoryArena *arena, char *fmt, va_list args);
API CString str_pushf(CMemoryArena *arena, char *fmt, ...);
API void    str_list_pushf(CMemoryArena *arena, CStringList *list, char *fmt,
                           ...);
