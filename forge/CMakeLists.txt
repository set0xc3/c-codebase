cmake_minimum_required(VERSION 3.10)

project(forge)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(TARGET_ARCHITECTURE "x64")

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/asset/asset.c
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/audio/audio.c
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/container/string8.c
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/container/vector2.c
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/container/vector3.c
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/container/vector4.c
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/logger/logger.c
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/graphics/graphics.c
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/graphics/window.c
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/input/input.c
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/math/math.c
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/memory/arena.c
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/forge.c
)

add_library(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
target_link_libraries(${PROJECT_NAME} PRIVATE
    dl m SDL2 SDL2_mixer SDL2_image
)
endif()
