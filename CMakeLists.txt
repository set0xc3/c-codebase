cmake_minimum_required(VERSION 3.10)
project(forge)
set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(TARGET_ARCHITECTURE "x64")

set(FRAMEWORK_SOURCES
    ${PROJECT_SOURCE_DIR}/src/forge_audio.c
    ${PROJECT_SOURCE_DIR}/src/forge_gfx.c
    ${PROJECT_SOURCE_DIR}/src/forge_input.c
    ${PROJECT_SOURCE_DIR}/src/forge_log.c
    ${PROJECT_SOURCE_DIR}/src/forge_string.c
    ${PROJECT_SOURCE_DIR}/src/forge.c
    ${PROJECT_SOURCE_DIR}/src/forge_window.c
)

add_library(${PROJECT_NAME}
    ${FRAMEWORK_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
target_link_libraries(${PROJECT_NAME} PRIVATE
    dl m SDL2 SDL2_mixer
)
endif()
