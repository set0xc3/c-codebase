#ifndef FORGE_LOGGER_H
#define FORGE_LOGGER_H

#include "forge/platform/platform.h"

EXPORT_LIB void log_info(const char *format, ...);
EXPORT_LIB void log_warning(const char *format, ...);
EXPORT_LIB void log_error(const char *format, ...);

#endif // FORGE_LOGGER_H
