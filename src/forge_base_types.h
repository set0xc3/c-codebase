#ifndef FORGE_BASE_TYPES_H
#define FORGE_BASE_TYPES_H

#include <stdint.h>

#define local_variable static
#define global_variable static
#define internal static

#define Bytes(value) (value)
#define Kilobytes(value) (value << 10)
#define Megabytes(value) (value << 20)
#define Gigabytes(value) ((uint64_t)(value) << 30)
#define Terabytes(value) ((uint64_t)(value) << 40)

#define ArrayCount(a) (sizeof((a)) / sizeof(*(a)))

#endif // FORGE_BASE_TYPES_H
