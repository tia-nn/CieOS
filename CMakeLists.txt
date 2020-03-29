cmake_minimum_required(VERSION 3.15)
project(CieOS C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -masm=intel")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -masm=intel")

include_directories(include)
add_library(CieOS SHARED
        src/main.c
        src/graphics/output.c
        src/font/hankaku.c
        src/std.c src/graphics/console.c include/graphics/console.h)

set_target_properties(CieOS PROPERTIES PREFIX "")
set_target_properties(CieOS PROPERTIES OUTPUT_NAME "kernel")
set_target_properties(CieOS PROPERTIES SUFFIX ".elf")