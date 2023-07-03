#ifndef FORGE_MEMORY_H
#define FORGE_MEMORY_H

#include "forge/base/base.h"
#include "forge/platform/platform.h"

// MemoryArena

typedef struct MemoryArena     MemoryArena;
typedef struct MemoryArenaTemp MemoryArenaTemp;

EXPORT_LIB MemoryArena *arena_create(u64 size);
EXPORT_LIB void         arena_destroy(MemoryArena *arena);
EXPORT_LIB void        *arena_push(MemoryArena *arena, u64 size);
EXPORT_LIB void        *arena_push_zero(MemoryArena *arena, u64 size);
EXPORT_LIB void        *arena_pop(MemoryArena *arena, u64 size);
EXPORT_LIB void         arena_clear(MemoryArena *arena);
EXPORT_LIB u64          arena_offset_get(MemoryArena *arena);

// MemoryArenaTemp

EXPORT_LIB MemoryArenaTemp arena_temp_begin(MemoryArena *arena);
EXPORT_LIB void            arena_temp_end(MemoryArenaTemp temp);
EXPORT_LIB MemoryArenaTemp arena_temp_scratch_get(MemoryArena *arena);

#endif // FORGE_MEMORY_H
