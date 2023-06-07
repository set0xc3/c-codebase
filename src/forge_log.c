#include "forge_log.h"

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { INFO, WARNING, ERROR } Log_Type;

void log_message(Log_Type type, const char *format, va_list args) {
    char *buffer = NULL;
    FILE *stream = NULL;
    const char *prefix = "";
    const int32_t prefix_width = 8;

    switch (type) {
    case INFO:
        stream = stdout;
        prefix = "INFO:";
        break;
    case WARNING:
        stream = stderr;
        prefix = "WARNING:";
        break;
    case ERROR:
        stream = stderr;
        prefix = "ERROR:";
        break;
    default:
        stream = stdout;
        break;
    }

    va_list args_copy;
    va_copy(args_copy, args);
    int32_t buffer_size = vsnprintf(NULL, 0, format, args_copy);
    va_end(args_copy);

    buffer = alloca(buffer_size + 1);
    vsnprintf(buffer, buffer_size + 1, format, args);

    fprintf(stream, "%-*s %s%*s", prefix_width, prefix, "",
            (int32_t)(strlen(prefix) - strlen(buffer)), buffer);
}

void log_info(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log_message(INFO, format, args);
    va_end(args);
}

void log_warning(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log_message(WARNING, format, args);
    va_end(args);
}

void log_error(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log_message(ERROR, format, args);
    va_end(args);
}