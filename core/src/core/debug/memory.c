#include "core/core.h"

void
debug_memory_handle(CCoreState *core)
{
    u64 memory_used = 0;

    for (u64 i = 0; i < core->debug->memory_block_count; i++)
    {
        CDebugMemoryBlock *block = &core->debug->memory_blocks[i];
        if (block->memory)
        {
            memory_used += block->size;

            // LOG_DEBUG("memory.block: %s:%lu\n", block->file_path,
            // block->line);
        }
    }

    LOG_DEBUG("memory.total     (0)\n");
    LOG_DEBUG("memory.used      (%ld)\n", memory_used);
    LOG_DEBUG("memory.available (0)\n");
    LOG_DEBUG("memory.cached    (0)\n");
    LOG_DEBUG("memory.freed     (0)\n");
}

void *
_debug_memory_alloc(CCoreState *core, u64 size, const char *file_path,
                    u64 line)
{
    void *memory = malloc(size);
    if (memory == NULL)
    {
        LOG_ERROR("Failed allocate memory\n");
    }

    if (core->debug->memory_block_count < PROFILER_MEMORY_BLOCKS_MAX)
    {
        CDebugMemoryBlock *block
            = &core->debug->memory_blocks[core->debug->memory_block_count];
        block->memory    = memory;
        block->size      = size;
        block->file_path = file_path;
        block->line      = line;
        core->debug->memory_block_count++;

        // LOG_DEBUG("memory.alloced: %s:%lu\n", block->file_path,
        // block->line);
    }

    return memory;
}

void
_debug_memory_free(CCoreState *core, void *memory, const char *file_path,
                   u64 line)
{
    if (core->debug->memory_block_count > 0)
    {
        CDebugMemoryBlock *top_block
            = &core->debug->memory_blocks[core->debug->memory_block_count - 1];

        for (u64 i = 0; i < core->debug->memory_block_count; i++)
        {
            CDebugMemoryBlock *block = &core->debug->memory_blocks[i];

            if (block->memory == memory)
            {
                memcpy(block, top_block, sizeof(CDebugMemoryBlock));
                core->debug->memory_block_count--;

                // LOG_DEBUG("memory.freed: %s:%lu\n", file_path, line);
                break;
            }
        }
    }

    free(memory);
}

void
_debug_memory_zero(void *memory, u64 size, const char *file_path, u64 line)
{
    memset(memory, 0, size);

    // LOG_DEBUG("memory.zero: %s:%lu\n", file_path, line);
}

void
_debug_memory_copy(void *dest, void *src, u64 size, const char *file_path,
                   u64 line)
{
    memcpy(dest, src, size);
    // LOG_DEBUG("memory.copy: %s:%lu\n", file_path, line);
}
