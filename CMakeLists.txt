cmake_minimum_required(VERSION 3.10)

project(forge)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(TARGET_ARCHITECTURE "x64")

set(PROJECT_SOURCES
    src/${PROJECT_NAME}/asset/asset.c
    src/${PROJECT_NAME}/audio/audio.c
    src/${PROJECT_NAME}/container/string8.c
    src/${PROJECT_NAME}/container/vector2.c
    src/${PROJECT_NAME}/container/vector3.c
    src/${PROJECT_NAME}/container/vector4.c
    src/${PROJECT_NAME}/logger/logger.c
    src/${PROJECT_NAME}/graphics/graphics.c
    src/${PROJECT_NAME}/graphics/window.c
    src/${PROJECT_NAME}/input/input.c
    src/${PROJECT_NAME}/math/math.c
    src/${PROJECT_NAME}/memory/arena.c
    src/${PROJECT_NAME}/forge.c
)

add_library(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    src
)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
target_link_libraries(${PROJECT_NAME} PRIVATE
    dl m SDL2 SDL2_mixer SDL2_image
)
endif()
