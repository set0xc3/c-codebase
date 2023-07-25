#include "core/core.h"

#include <stdarg.h>

const char *logger_types_string[LoggerType_Count] = {
    "INFO",
    "DEBUG",
    "WARNING",
    "ERROR",
};

void
log_message(CCoreState *core, CLoggerType type, const char *format,
            va_list args)
{
    char       *buffer       = NULL;
    FILE       *stream       = NULL;
    const char *prefix       = "";
    const u32   prefix_width = 8;

    stream = stdout;
    prefix = logger_types_string[type];

    va_list args_copy;
    va_copy(args_copy, args);
    u64 buffer_size = vsnprintf(NULL, 0, format, args_copy);
    va_end(args_copy);

    buffer = MemoryAllocArray(char, buffer_size + 1);
    vsnprintf(buffer, buffer_size + 1, format, args);

    const u32 padding = prefix_width - (u32)strlen(prefix);
    fprintf(stream, " - %s:", prefix);
    fprintf(stream, "%*s %s", padding, "", buffer);
}

void
log_print(CCoreState *core, CLoggerType type, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    log_message(core, type, format, args);
    va_end(args);
}
