#ifndef FORGE_PLATFORM_TYPES_H
#define FORGE_PLATFORM_TYPES_H

#ifdef __linux__
#define PLATFORM_LINUX
#elif __WIN32__
#define PLATFORM_WINDOWS
#endif

#ifdef PLATFORM_LINUX
#define PLATFORM_LIB_EXT "so"
#define PLATFORM_SLASH '/'
#elif PLATFORM_WINDOWS
#define PLATFORM_LIB_EXT "dll"
#define PLATFORM_SLASH '\'
#endif

#ifdef PLATFORM_LINUX
#define EXPORT_LIB __attribute__((visibility("default")))
#define IMPORT_LIB
#elif PLATFORM_WINDOWS
#define EXPORT_LIB __declspec(dllexport)
#define IMPORT_LIB __declspec(dllimport)
#else
#define EXPORT_LIB
#define IMPORT_LIB
#endif

#endif // FORGE_PLATFORM_TYPES_H
