#ifndef CORE_H
#define CORE_H

#include <SDL2/SDL.h>

// Base Types

#include <assert.h>
#include <memory.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float  f32;
typedef double f64;

typedef i8  b8;
typedef i16 b16;
typedef i32 b32;
typedef i64 b64;

#define local_variable  static
#define global_variable static
#define internal        static

#define Bytes(value)     (value)
#define Kilobytes(value) (value << 10)
#define Megabytes(value) (value << 20)
#define Gigabytes(value) ((u64)(value) << 30)
#define Terabytes(value) ((u64)(value) << 40)

#define ArrayCount(a) (sizeof((a)) / sizeof(*(a)))

// Platform Types

#ifdef __linux__
#define LINUX
#elif defined(__WIN32__)
#define WINDOWS
#endif

#ifdef LINUX
#define LIBRARY_EXTENSION "so"
#define PATH_SLASH        '/'
#elif defined(WINDOWS)
#define LIBRARY_EXTENSION "dll"
#define PATH_SLASH        '\\'
#endif

#ifdef LINUX
#ifdef EXPORT
#define API __attribute__((dllexport))
#else
#define API __attribute__((dllimport))
#endif // EXPORT
#elif defined(WINDOWS)
#ifdef EXPORT
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif // EXPORT
#endif

// Structures
typedef struct CString8           CString8;
typedef union CVector2            CVector2;
typedef union CVector3            CVector3;
typedef union CVector4            CVector4;
typedef struct CImage             CImage;
typedef struct CAsset             CAsset;
typedef struct CAudio             CAudio;
typedef struct CDebugMemoryBlock  CDebugMemoryBlock;
typedef struct CDebugProfilerFunc CDebugProfilerFunc;
typedef struct CDebugState        CDebugState;
typedef char                     *CEntityID;
typedef enum CEntityFlags         CEntityFlags;
typedef struct CEntity            CEntity;
typedef struct CSceneState        CSceneState;
typedef struct CWindow            CWindow;
typedef enum CEventCode           CEventCode;
typedef struct CEvent             CEvent;
typedef struct CEventListener     CEventListener;
typedef struct CEventState        CEventState;
typedef enum CMouseButton         CMouseButton;
typedef enum CKeyCode             CKeyCode;
typedef struct CKeyboardState     CKeyboardState;
typedef struct CMouseState        CMouseState;
typedef struct CInputState        CInputState;
typedef struct CModuleAPI         CModuleAPI;
typedef struct CLayer             CLayer;
typedef struct CLibrary           CLibrary;
typedef enum CLoggerType          CLoggerType;
typedef struct CMemoryArena       CMemoryArena;
typedef struct CMemoryArenaTemp   CMemoryArenaTemp;
typedef struct CMouduleMemory     CMouduleMemory;
typedef struct CCoreState         CCoreState;

typedef b8 (*event_on_listener)(u32 code, CEvent event);

// Core Interface

struct CCoreState
{
    CDebugState *debug;
    CSceneState *scene;
    CWindow     *window;
    CEventState *event;
    CInputState *input;
    CLayer      *layer;
    CLibrary    *game_dll;
};

API void core_startup(CCoreState *core);
API void core_update(CCoreState *core);
API void core_shutdown(CCoreState *core);
API b8   core_poll_event(CCoreState *core);
API void core_sleep(CCoreState *core, u32 ms);
API u64  core_perf_counter(CCoreState *core);
API u64  core_perf_frequency(CCoreState *core);

// Container Interface

API u64 hash_string_fnv1a64(const char *str);

// CString8

struct CString8
{
    u8 *str;
    u64 size;
};

API CString8 str8(const char *c);
API b8       str8_eq(const CString8 left, const CString8 right);
API CString8 str8_concat(CMemoryArena *arena, CString8 dest,
                         CString8 src); // TODO
API CString8 str8_replace(CMemoryArena *arena, CString8 dest,
                          CString8 src); // TODO

#define str8_c(s) (const char *)s.str

// CVector2

union CVector2
{
    struct
    {
        f32 x, y;
    };

    struct
    {
        f32 u, v;
    };

    struct
    {
        f32 left, right;
    };

    struct
    {
        f32 width, height;
    };

    f32 elements[2];
};

API CVector2 v2(f32 x, f32 y);
API CVector2 v2_add(CVector2 left, CVector2 right);
API CVector2 v2_addf(CVector2 left, f32 right);
API CVector2 v2_sub(CVector2 left, CVector2 right);
API CVector2 v2_subf(CVector2 left, f32 right);
API CVector2 v2_mul(CVector2 left, CVector2 right);
API CVector2 v2_mulf(CVector2 left, f32 right);
API CVector2 v2_div(CVector2 left, CVector2 right);
API CVector2 v2_divf(CVector2 left, f32 right);
API f32      v2_dot(CVector2 left, CVector2 right);
API b8       v2_eq(CVector2 left, CVector2 right);
API CVector2 v2_norm(CVector2 v);
API f32      v2_sqrt_len(CVector2 v);
API f32      v2_len(CVector2 v);
API CVector2 v2_lerp(CVector2 left, CVector2 right, f32 time);

// CVector3

union CVector3
{
    struct
    {
        f32 x, y, z;
    };

    struct
    {
        f32 u, v, w;
    };

    struct
    {
        f32 r, g, b;
    };

    struct
    {
        CVector2 xy;
        f32      _ignored0;
    };

    struct
    {
        f32      _ignored1;
        CVector2 yz;
    };

    struct
    {
        CVector2 uv;
        f32      _ignored2;
    };

    struct
    {
        f32      _ignored3;
        CVector2 vw;
    };

    f32 elements[3];
};

API CVector3 v3(f32 x, f32 y, f32 z);
API CVector3 v3_add(CVector3 left, CVector3 right);
API CVector3 v3_sub(CVector3 left, CVector3 right);
API CVector3 v3_mul(CVector3 left, CVector3 right);
API CVector3 v3_mulf(CVector3 left, f32 right);
API CVector3 v3_div(CVector3 left, CVector3 right);
API CVector3 v3_divf(CVector3 left, f32 right);
API f32      v3_dot(CVector3 left, CVector3 right);
API b8       v3_eq(CVector3 left, CVector3 right);
API CVector3 v3_norm(CVector3 v);
API f32      v3_sqrt_len(CVector3 v);
API f32      v3_len(CVector3 v);
API CVector3 v3_lerp(CVector3 left, CVector3 right, f32 time);

// CVector4

union CVector4
{
    struct
    {
        union
        {
            CVector3 xyz;
            struct
            {
                f32 x, y, z;
            };
        };

        f32 w;
    };

    struct
    {
        union
        {
            CVector3 rgb;
            struct
            {
                f32 r, g, b;
            };
        };

        f32 a;
    };

    struct
    {
        CVector2 xy;
        f32      _ignored0;
        f32      _ignored1;
    };

    struct
    {
        f32      _ignored2;
        CVector2 yz;
        f32      _ignored3;
    };

    struct
    {
        f32      _ignored4;
        f32      _ignored5;
        CVector2 zw;
    };

    struct
    {
        f32 left, right, top, botton;
    };

    struct
    {
        f32 _ignored6;
        f32 _ignored7;
        f32 width, height;
    };

    f32 elements[4];
};

API CVector4 v4(f32 x, f32 y, f32 z, f32 w);
API CVector4 v4_add(CVector4 left, CVector4 right);
API CVector4 v4_sub(CVector4 left, CVector4 right);
API CVector4 v4_mul(CVector4 left, CVector4 right);
API CVector4 v4_mulf(CVector4 left, f32 right);
API CVector4 v4_div(CVector4 left, CVector4 right);
API CVector4 v4_divf(CVector4 left, f32 right);
API f32      v4_dot(CVector4 left, CVector4 right);
API b8       v4_eq(CVector4 left, CVector4 right);
API CVector4 v4_norm(CVector4 v);
API f32      v4_sqrt_len(CVector4 v);
API f32      v4_len(CVector4 v);
API CVector4 v4_lerp(CVector4 left, CVector4 right, f32 time);

// Asset Interface

API void    asset_init(void);
API void    asset_destroy(void);
API void   *asset_file_rw_data_load(const char *file_path);
API CImage *asset_image_load(const char *file_path);
API void    asset_image_unload(CImage *image);
API void    asset_image_size_get(CImage *image, i16 *width, i16 *height);

// Audio Interface

API void    audio_init(void);
API CAudio *audio_load(const char *file_path);
API void    audio_unload(CAudio *audio_state);
API void    audio_play(CAudio *audio_state, bool loop);
API void    audio_stop(CAudio *audio_state);

// Debug Interface

#define PROFILER_MEMORY_BLOCKS_MAX 1000
#define PROFILER_FUNCTIONS_MAX     1000

struct CDebugMemoryBlock
{
    void       *memory;
    u64         size;
    const char *file_path;
    u32         line;
};

struct CDebugProfilerFunc
{
    const char *name;
    u64         cycle_count;
    u64         hit_count;
};

struct CDebugState
{
    CDebugMemoryBlock memory_blocks[PROFILER_MEMORY_BLOCKS_MAX];
    u64               memory_block_count;

    CDebugProfilerFunc functions[PROFILER_FUNCTIONS_MAX];
    u64                function_count;
};

// Debug profiler Interface

void debug_profiler_startup(CCoreState *core);
void debug_profiler_shutdown(CCoreState *core);
void debug_profiler_handle(CCoreState *core);

CDebugProfilerFunc *debug_profiler_function_add(CCoreState *core,
                                                const char *func_name);
CDebugProfilerFunc *debug_profiler_function_find(CCoreState *core,
                                                 const char *func_name);
API void            debug_startup(CCoreState *core);
API void            debug_shutdown(CCoreState *core);
API void            debug_update(CCoreState *core);

API void *_debug_profiler_timed_block_begin(CCoreState *core,
                                            const char *func_name);
API void  _debug_profiler_timed_block_end(void *counter_ptr, u64 cycle_count);

#define PROFILER_BEGIN(NAME)                                                  \
    void *current_counter_##NAME = _debug_profiler_timed_block_begin(#NAME);  \
    u64   start_##NAME           = core_perf_counter();

#define PROFILER_END(NAME)                                                    \
    u64 end_##NAME = core_perf_counter();                                     \
    _debug_profiler_timed_block_end(current_counter_##NAME,                   \
                                    end_##NAME - start_##NAME);

// Debug memory Interface

API void debug_memory_handle(CCoreState *core);

API void *_debug_memory_alloc(CCoreState *core, u64 size,
                              const char *file_path, u64 line);
API void  _debug_memory_free(CCoreState *core, void *memory,
                             const char *file_path, u64 line);
API void  _debug_memory_zero(void *memory, u64 size, const char *file_path,
                             u64 line);
API void  _debug_memory_copy(void *dest, void *src, u64 size,
                             const char *file_path, u64 line);

// Entity Interface

enum CEntityFlags
{
    EntityFlag_Active     = 1 << 0,
    EntityFlag_Renderable = 1 << 1,
    EntityFlag_Everything = 0xFFFFFFFF,
};

struct CEntity
{
    CEntityID    uuid;
    CEntityFlags flags;
    b8           enabled;

    CVector3 position;
    CVector4 quaternion;
    CVector3 scale;
};

// Scene Interface

#define SCENE_ENTITIES_MAX 1000

struct CSceneState
{
    char *path;
    b8    edited;
    b8    dirtied;

    CEntityID *entities_selected;
    u64        entities_selected_count;
    CEntity   *entities;
    u64        entities_count;
};

API void scene_startup(CCoreState *core);
API void scene_update(CCoreState *core, f32 dt);
API void scene_shutdown(CCoreState *core);
API void scene_clear(CCoreState *core);

API CEntity *scene_entity_create(CCoreState *core);
API void     scene_entity_destroy(CCoreState *core, CEntity *entity);

// UUID Interface
API char *uuid_gen(void); // NOTE: allocates memory!

// Window Interface

struct CWindow
{
    SDL_Window   *handle;
    SDL_Renderer *renderer;
    SDL_Texture  *texture;
    const char   *title;
    struct
    {
        i32 x, y;
        i32 width, height;
    } rect;
};

API CWindow *window_open(CCoreState *core, const char *title, i32 xpos,
                         i32 ypos, i32 width, i32 height);
API void     window_close(CCoreState *core, CWindow *window);
API b8       window_poll_events(CCoreState *core);

// Event Interface

#define EVENT_LISTENERS_MAX 1000

enum CEventCode
{
    EventCode_AppQuit        = 1 << 0,
    EventCode_KeyPressed     = 1 << 1,
    EventCode_KeyReleased    = 1 << 2,
    EventCode_ButtonPressed  = 1 << 3,
    EventCode_ButtonReleased = 1 << 4,
    EventCode_MouseMotion    = 1 << 5,
    EventCode_MouseWheel     = 1 << 6,
    EventCode_WindowResized  = 1 << 7,
    EventCode_WindowClosed   = 1 << 8,
    EventCode_Everything     = 0xFFFFFFFF,
    EventCode_Count          = 9,
};

struct CEvent
{
    // 128 bites
    union
    {
        i64 i64[2];
        u64 u64[2];
        f64 f64[2];

        i32 i32[4];
        u32 u32[4];
        f32 f32[4];

        i16 i16[8];
        u16 u16[8];

        i8 i8[16];
        u8 u8[16];

        char c[16];
    } data;
};

struct CEventListener
{
    u32               code;
    event_on_listener callback;
};

struct CEventState
{
    CEventListener *listeners;
    u64             listeners_count;
};

API b8 event_startup(CCoreState *core);
API b8 event_shutdown(CCoreState *core);
API b8 event_register(CCoreState *core, u32 code,
                      event_on_listener on_listener);
API b8 event_unregister(CCoreState *core, u32 code,
                        event_on_listener on_listener);
API b8 event_fire(CCoreState *core, u32 code, CEvent event);

// Input Interface

enum CMouseButton
{
    MouseButton_Left,
    MouseButton_Middle,
    MouseButton_Right,
    MouseButton_Count,
};

enum CKeyCode
{
    KeyCode_A,
    KeyCode_D,
    KeyCode_W,
    KeyCode_S,
    KeyCode_Q,
    KeyCode_E,
    KeyCode_Escape,
    KeyCode_Count,
};

struct CKeyboardState
{
    b8 keys[KeyCode_Count];
};

struct CMouseState
{
    i32 x, y;
    i32 wheel;
    b8  buttons[MouseButton_Count];
};

struct CInputState
{
    CKeyboardState keyboard_current;
    CKeyboardState keyboard_previous;

    CMouseState mouse_current;
    CMouseState mouse_previous;
};

API void input_startup(CCoreState *core);
API void input_shutdown(CCoreState *core);

API void input_button_process(CCoreState *core, u32 button, b8 pressed);
API void input_key_process(CCoreState *core, u32 key, b8 pressed);
API void input_mouse_motion_process(CCoreState *core, i32 x, i32 y);
API void input_mouse_scroll_process(CCoreState *core, i32 delta);

API void input_update(CCoreState *core);
API b8   input_button_pressed(CCoreState *core, u32 button);
API b8   input_button_down(CCoreState *core, u32 button);
API b8   input_button_up(CCoreState *core, u32 button);
API b8   input_key_pressed(CCoreState *core, u32 key);
API b8   input_key_down(CCoreState *core, u32 key);
API b8   input_key_up(CCoreState *core, u32 key);
API void input_mouse_position_get(CCoreState *core, i32 *x, i32 *y);
API void input_mouse_wheel_get(CCoreState *core, i32 *delta);

// Module Interface

struct CModuleAPI
{
    void (*startup)(void);
    void (*update)(f32 dt);
    void (*shutdown)(void);
};

API void module_startup_stub(void);
API void module_update_stub(f32 dt);
API void module_shutdown_stub(void);

// Layer Interface

struct CLayer
{
    b8         is_valid;
    CModuleAPI api;
};

API void layer_main(CLayer *layer);

// Library Interface

struct CLibrary
{
    b8         is_valid;
    void      *handle;
    CModuleAPI api;
};

API CLibrary library_load(CCoreState *core, const char *path);
API void     library_unload(CCoreState *core, CLibrary *library);
API void    *library_load_function(CCoreState *core, CLibrary *library,
                                   const char *name);

// Logger Interface

enum CLoggerType
{
    LoggerType_Info,
    LoggerType_Debug,
    LoggerType_Warning,
    LoggerType_Error,
    LoggerType_Count,
};

API void log_print(CCoreState *core, CLoggerType type, const char *format,
                   ...);

#define LOG_INFO(format, ...)                                                 \
    log_print(core, LoggerType_Info, format, ##__VA_ARGS__)
#define LOG_DEBUG(format, ...)                                                \
    log_print(core, LoggerType_Debug, format, ##__VA_ARGS__)
#define LOG_WARRNING(format, ...)                                             \
    log_print(core, LoggerType_Warrning, format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...)                                                \
    log_print(core, LoggerType_Error, format, ##__VA_ARGS__)

// Math Interface

#define COLOR_RED         v4(1.0f, 0.0f, 0.0f, 1.0f)
#define COLOR_RED_DARK    v4(0.5f, 0.0f, 0.0f, 1.0f)
#define COLOR_GREEN       v4(0.0f, 1.0f, 0.0f, 1.0f)
#define COLOR_GREEN_DARK  v4(0.0f, 0.5f, 0.0f, 1.0f)
#define COLOR_BLUE        v4(0.0f, 0.0f, 1.0f, 1.0f)
#define COLOR_BLUE_DARK   v4(0.0f, 0.0f, 0.5f, 1.0f)
#define COLOR_PINK        v4(1.0f, 0.0f, 1.0f, 1.0f)
#define COLOR_PINK_DARK   v4(0.5f, 0.0f, 0.5f, 1.0f)
#define COLOR_YELLOW      v4(1.0f, 1.0f, 0.0f, 1.0f)
#define COLOR_YELLOW_DARK v4(0.5f, 0.5f, 0.0f, 1.0f)
#define COLOR_CYAN        v4(0.0f, 1.0f, 1.0f, 1.0f)
#define COLOR_CYAN_DARK   v4(0.0f, 0.5f, 0.5f, 1.0f)
#define COLOR_WHITE       v4(1.0f, 1.0f, 1.0f, 1.0f)
#define COLOR_BLACK       v4(0.0f, 0.0f, 0.0f, 1.0f)

API f32 m_radiansf(f32 degree);
API f32 m_degreesf(f32 radian);
API f64 m_radians(f64 degree);
API f64 m_degrees(f64 radian);

// Memory Interface

struct CMemoryArena
{
    u8 *data;
    u64 size;
    u64 pos;
};

struct CMemoryArenaTemp
{
    CMemoryArena *arena;
    u64           pos;
};

#ifndef NDEBUG
#define MemoryAlloc(type, size)                                               \
    (type *)_debug_memory_alloc(core, size * sizeof(type), __FILE__, __LINE__)
#define MemoryFree(memory) _debug_memory_free(core, memory, __FILE__, __LINE__)
#define MemoryZero(memory, type, size)                                        \
    _debug_memory_zero(memory, size * sizeof(type), __FILE__, __LINE__)
#define MemoryCopy(dest, src, type, size)                                     \
    _debug_memory_copy(dest, src, size * sizeof(type), __FILE__, __LINE__)
#else
#define MemoryAlloc(type, size)        (type *)malloc(size * sizeof(type))
#define MemoryFree(memory)             free(memory)
#define MemoryZero(memory, type, size) memset(memory, 0, size * sizeof(type))
#define MemoryCopy(dest, src, type, size)                                     \
    memcpy(dest, src, size * sizeof(type))
#endif

#define MemoryAllocArray(type, size)        MemoryAlloc(type, size)
#define MemoryAllocStruct(type)             MemoryAlloc(type, 1)
#define MemoryZeroArray(memory, type, size) MemoryZero(memory, type, size)
#define MemoryZeroStruct(memory, type)      MemoryZero(memory, type, 1)
#define MemoryCopyArray(dest, src, type, size)                                \
    MemoryCopy(dest, src, type, size)
#define MemoryCopyStruct(dest, src, type) MemoryCopy(dest, src, type, 1)

API CMemoryArena *arena_create(CCoreState *core, u64 size);
API void          arena_destroy(CCoreState *core, CMemoryArena *arena);
API void         *arena_push(CCoreState *core, CMemoryArena *arena, u64 size);
API void *arena_push_zero(CCoreState *core, CMemoryArena *arena, u64 size);
API void *arena_pop(CCoreState *core, CMemoryArena *arena, u64 size);
API void  arena_clear(CMemoryArena *arena);
API u64   arena_offset_get(CMemoryArena *arena);

API CMemoryArenaTemp arena_temp_begin(CMemoryArena *arena);
API void             arena_temp_end(CMemoryArenaTemp temp);
API CMemoryArenaTemp arena_temp_scratch_get(CMemoryArena *arena);

#define PushArray(arena, type, count)                                         \
    (type *)arena_push(arena, count * sizeof(type))
#define PushArrayZero(arena, type, count)                                     \
    (type *)arena_push_zero(arena, count * sizeof(type))
#define PushStruct(arena, type)     PushArray(arena, 1)
#define PushStructZero(arena, type) PushArrayZero(arena, 1)
#define PopArray(arena, type, count)                                          \
    (type *)arena_pop(arena, count * sizeof(type))
#define PopStruct(arena, type) PopArray(arena, 1)

// Module Interface

struct CMouduleMemory
{
    b8            is_initialized;
    CMemoryArena *permanent_storage;
    CMemoryArena *transient_storage;
};

#endif // CORE_H
