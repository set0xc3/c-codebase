#pragma once

#include "ccb/base/defines.h"

typedef enum CLoggerType
{
    LoggerType_Info,
    LoggerType_Debug,
    LoggerType_Warning,
    LoggerType_Error,
    LoggerType_Count,
} CLoggerType;

API void log_print(CLoggerType type, const char *format, ...);

#define LOG_INFO(format, ...) log_print(LoggerType_Info, format, ##__VA_ARGS__)
#define LOG_DEBUG(format, ...)                                                \
    log_print(LoggerType_Debug, format, ##__VA_ARGS__)
#define LOG_WARRNING(format, ...)                                             \
    log_print(LoggerType_Warrning, format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...)                                                \
    log_print(LoggerType_Error, format, ##__VA_ARGS__)
