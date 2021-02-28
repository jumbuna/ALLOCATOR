cmake_minimum_required(VERSION 3.19)

project(LIBALLOCATOR VERSION 1.0 LANGUAGES C)

add_library(allocator SHARED allocator.c)

target_include_directories(allocator INTERFACE "${CMAKE_SOURCE_DIR}/include/allocator.h")

install(TARGETS allocator DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")

install(FILES "${CMAKE_SOURCE_DIR}/include/allocator.h"
        DESTINATION "${CMAKE_INSTALL_PREFIX}/include/allocator")