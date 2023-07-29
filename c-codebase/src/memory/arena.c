#include "memory/arena.h"
#include "core/logger.h"

CMemoryArena *
arena_create(u64 size)
{
    CMemoryArena *arena = MemoryAllocStruct(CMemoryArena);
    arena->memory       = MemoryAllocArray(u8, size);
    arena->size         = size;
    arena->pos          = 0;
    return arena;
}

void
arena_destroy(CMemoryArena *arena)
{
    MemoryFree(arena->memory);
    MemoryFree(arena);
}

void *
arena_push(CMemoryArena *arena, u64 size)
{
    if (arena->pos + size > arena->size)
    {
        LOG_ERROR("Handle out-of-memory\n");
        assert(true);
    }

    void *pos = arena->memory + arena->pos;
    arena->pos += size;
    return pos;
}

void *
arena_push_zero(CMemoryArena *arena, u64 size)
{
    void *memory = arena_push(arena, size);
    memset(memory, 0, size);
    return memory;
}

void *
arena_pop(CMemoryArena *arena, u64 size)
{
    if (arena->pos == 0)
    {
        LOG_ERROR("Handle out-of-memory\n");
        assert(true);
    }

    arena->pos -= size;
    void *pos = arena->memory + arena->pos - size;
    return pos;
}

void
arena_clear(CMemoryArena *arena)
{
    arena->pos = 0;
}

u64
arena_offset_get(CMemoryArena *arena)
{
    return arena->pos;
}

CMemoryArenaTemp
arena_temp_begin(CMemoryArena *arena)
{
    CMemoryArenaTemp result = { 0 };
    result.arena            = arena;
    result.pos              = arena->pos;
    return result;
}

void
arena_temp_end(CMemoryArenaTemp temp)
{
    temp.arena->pos = temp.pos;
}

CMemoryArenaTemp
arena_temp_scratch_get(CMemoryArena *arena)
{
    CMemoryArenaTemp temp = { 0 };
    temp.arena            = arena;
    temp.pos              = arena->pos;
    return temp;
}
