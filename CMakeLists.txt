cmake_minimum_required(VERSION 3.16)
project(papaya)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES
    "src/Papaya.cpp"
    "src/PapayaError.cpp"
    "src/PapayaPrivate.cpp"
    "main.cpp"
)

add_executable(papaya ${SOURCES})

#  ---- POST BUILD ---- #
add_custom_command(TARGET papaya POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:papaya> ${CMAKE_SOURCE_DIR}
)
