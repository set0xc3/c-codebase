#ifndef FORGE_BASE_TYPES_H
#define FORGE_BASE_TYPES_H

#include <stdint.h>
#include <stdbool.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef i8 b8;
typedef i16 b16;
typedef i32 b32;
typedef i64 b64;

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
