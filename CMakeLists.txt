cmake_minimum_required(VERSION 3.15)
project(CieOS C ASM)

set(CMAKE_C_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -masm=intel -Wno-builtin-declaration-mismatch -mgeneral-regs-only -g3")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -masm=intel")

include_directories(include)
add_library(CieOS SHARED
        src/std.c
        src/font/hankaku.c
        src/descriptor/segment.c
        src/descriptor/interrupt.c
        src/graphics/draw.c
        src/graphics/print.c
        src/memory_allocator/print.c
        src/main.c
        src/pic.c
        src/interrupt_handler/timer.c
        src/interrupt_handler/timer.s
        src/interrupt_handler/general_protect.c
        src/interrupt_handler/keyboard.c
        src/schedule.c

        src/interrupt_default_handler/int_default.c
        src/interrupt_default_handler/int_defalut_handler_array.c
        )

set_target_properties(CieOS PROPERTIES PREFIX "")
set_target_properties(CieOS PROPERTIES OUTPUT_NAME "kernel")
set_target_properties(CieOS PROPERTIES SUFFIX ".elf")

set(DIST_PATH "~/Projects/Qemu/test/kernel.elf")
add_custom_command(TARGET CieOS COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:CieOS> ${DIST_PATH})
