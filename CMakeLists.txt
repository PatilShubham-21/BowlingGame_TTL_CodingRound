cmake_minimum_required(VERSION 3.16)
project(BowlingGame VERSION 1.0.0 LANGUAGES CXX)

add_executable(bowling
    "${CMAKE_CURRENT_SOURCE_DIR}/src/bowling.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)

set_target_properties(bowling
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)