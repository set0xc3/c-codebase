#include "ccb/core/logger.h"
#include "ccb/memory/arena.h"

const char *logger_types_string[LoggerType_Count] = {
    "INFO",
    "DEBUG",
    "WARNING",
    "ERROR",
};

void
log_print(u32 type, const char *time, const char *file_path, u32 line,
          const char *format, ...)
{
    va_list args;
    va_start(args, format);

    char       *buffer       = NULL;
    FILE       *stream       = NULL;
    const char *prefix       = "";
    const u32   prefix_width = 7;

    stream = stdout;
    prefix = logger_types_string[type];

    va_list args_copy;
    va_copy(args_copy, args);
    u64 buffer_size = vsnprintf(NULL, 0, format, args_copy);
    va_end(args_copy);

    buffer = MemoryAllocArray(char, buffer_size + 1);
    vsnprintf(buffer, buffer_size + 1, format, args);

    const u32 padding = prefix_width - (u32)strlen(prefix);
    fprintf(stream, "[%s] [%s]", time, prefix);
    fprintf(stream, "%*s [%s:%d] %s", padding, "", strrchr(file_path, '/') + 1,
            line, buffer);

    va_end(args);
}
