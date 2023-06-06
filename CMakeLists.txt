cmake_minimum_required(VERSION 3.10)
project(forge)
set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(TARGET_ARCHITECTURE "x64")

set(FRAMEWORK_SOURCES
    ${PROJECT_SOURCE_DIR}/src/forge_audio.c
    ${PROJECT_SOURCE_DIR}/src/forge_log.c
    ${PROJECT_SOURCE_DIR}/src/forge_string.c
)

add_library(${PROJECT_NAME}
    ${FRAMEWORK_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

add_custom_target(run
    COMMAND cd ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} && ./${PROJECT_NAME} ${ARGS}
)
