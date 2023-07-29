#pragma once

#include "base/defines.h"

typedef struct CMemoryArena
{
    void *memory;
    u64   size;
    u64   pos;
} CMemoryArena;

typedef struct CMemoryArenaTemp
{
    CMemoryArena *arena;
    u64           pos;
} CMemoryArenaTemp;

#define MemoryAlloc(type, size)        (type *)malloc(size * sizeof(type))
#define MemoryFree(memory)             free(memory)
#define MemoryZero(memory, type, size) memset(memory, 0, size * sizeof(type))
#define MemoryCopy(dest, src, type, size)                                     \
    memcpy(dest, src, size * sizeof(type))

#define MemoryAllocArray(type, size)        MemoryAlloc(type, size)
#define MemoryAllocStruct(type)             MemoryAlloc(type, 1)
#define MemoryZeroArray(memory, type, size) MemoryZero(memory, type, size)
#define MemoryZeroStruct(memory, type)      MemoryZero(memory, type, 1)
#define MemoryCopyArray(dest, src, type, size)                                \
    MemoryCopy(dest, src, type, size)
#define MemoryCopyStruct(dest, src, type) MemoryCopy(dest, src, type, 1)

API CMemoryArena *arena_create(u64 size);
API void          arena_destroy(CMemoryArena *arena);
API void         *arena_push(CMemoryArena *arena, u64 size);
API void         *arena_push_zero(CMemoryArena *arena, u64 size);
API void         *arena_pop(CMemoryArena *arena, u64 size);
API void          arena_clear(CMemoryArena *arena);
API u64           arena_offset_get(CMemoryArena *arena);

API CMemoryArenaTemp arena_temp_begin(CMemoryArena *arena);
API void             arena_temp_end(CMemoryArenaTemp temp);
API CMemoryArenaTemp arena_temp_scratch_get(CMemoryArena *arena);

#define PushArray(arena, type, count)                                         \
    (type *)arena_push(arena, count * sizeof(type))
#define PushArrayZero(arena, type, count)                                     \
    (type *)arena_push_zero(arena, count * sizeof(type))
#define PushStruct(arena, type)     PushArray(arena, 1)
#define PushStructZero(arena, type) PushArrayZero(arena, 1)
#define PopArray(arena, type, count)                                          \
    (type *)arena_pop(arena, count * sizeof(type))
#define PopStruct(arena, type) PopArray(arena, 1)
