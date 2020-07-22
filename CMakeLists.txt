cmake_minimum_required(VERSION 3.15)
project(CieOS C ASM)

set(CMAKE_C_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -masm=intel -Wno-builtin-declaration-mismatch -mgeneral-regs-only -g3")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -masm=intel")

include_directories(include)
add_library(CieOS SHARED
        src/std.c
        src/std.s
        src/font/hankaku.c
        src/descriptor/segment.c
        src/descriptor/interrupt.c
        src/graphics/draw.c
        src/graphics/print.c
        src/main.c
        src/pic.c
        src/interrupt_handler/timer.c
        src/interrupt_handler/timer.s
        src/interrupt_handler/general_protect.c
        src/interrupt_handler/keyboard.c
        src/interrupt_handler/systemcall.c
        src/interrupt_handler/systemcall.s
        src/paging.c
        src/file/read_hdd.c
        src/file/read_filesystem.c

        src/interrupt_default_handler/int_default.c
        src/interrupt_default_handler/int_defalut_handler_array.c

        src/interrupt_handler/page_fault.c
        src/tasks/tasks.c
        src/interrupt_handler/mause.c
        src/memory_allocator.c
        src/interrupt_handler/div_zero.c
        src/interrupt_handler/rtc.c
        src/keyboard-input.c)

set_target_properties(CieOS PROPERTIES PREFIX "")
set_target_properties(CieOS PROPERTIES OUTPUT_NAME "kernel")
set_target_properties(CieOS PROPERTIES SUFFIX ".elf")

set(DIST_PATH "~/Projects/Qemu/test/kernel.elf")
add_custom_command(TARGET CieOS COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:CieOS> ${DIST_PATH})

#set(DIST_PATH_2 "/run/media/tia/EB69-F2D4/kernel.elf")
#add_custom_command(TARGET CieOS COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:CieOS> ${DIST_PATH_2})
