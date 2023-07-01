cmake_minimum_required(VERSION 3.10)

project(forge)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(forge)
add_subdirectory(tests)

add_custom_target(test
    COMMAND cd ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} && ./tests ${ARGS}
)
