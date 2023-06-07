#ifndef FORGE_LOG_H
#define FORGE_LOG_H

#include "forge_platform_types.h"

EXPORT_LIB void log_info(const char *format, ...);
EXPORT_LIB void log_warning(const char *format, ...);
EXPORT_LIB void log_error(const char *format, ...);

#endif // FORGE_LOG_H
