cmake_minimum_required(VERSION 3.15)
project(CieOS C ASM)

set(CMAKE_C_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -masm=intel -Wno-builtin-declaration-mismatch -mgeneral-regs-only -g3")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -masm=intel")

include_directories(cpu-typing/include)
add_library(CieOS SHARED
        src/main.c
        src/bootloader.h
        src/initialize.c
        src/initialize.h
        src/descriptor.c
        src/descriptor.h
        src/tools.c
        src/tools.s
        src/tools.h
        src/print.c
        src/print.h
        src/hankaku.c
        src/hankaku.h
        )

set_target_properties(CieOS PROPERTIES PREFIX "")
set_target_properties(CieOS PROPERTIES OUTPUT_NAME "kernel")
set_target_properties(CieOS PROPERTIES SUFFIX ".elf")

set(DIST_PATH "~/Projects/Qemu/test/kernel.elf")
add_custom_command(TARGET CieOS COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:CieOS> ${DIST_PATH})
