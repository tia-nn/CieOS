#include <main.h>
#include <std.h>
#include <bootloader/graphics_config.h>
#include <bootloader/memory_map.h>
#include <graphics/draw.h>
#include <graphics/print.h>
#include <descriptor/segment.h>
#include <descriptor/interrupt.h>
#include <pic.h>
#include <interrupt_handler.h>
#include <control_registers.h>
#include <paging.h>
#include <file/read_hdd.h>
#include <tasks/tasks.h>
#include <memory_allocator.h>

__attribute__((always_inline)) void set_segment_register(uint16_t cs, uint16_t ds, uint16_t ss);

void _start(GraphicsConfig *graphics_config, MemoryMap *memory_map, void *acpi_table, void* code_top, void *entrypoint) {
    draw_init(graphics_config);

    KERNEL_LOADED_POINT = code_top;
    ENTRY_POINT = entrypoint;

    __asm__ volatile ("cli");

    GDT_init();
    M_LOAD_GDT();
    set_segment_register(8, 16, 16);

    mem_table_init(memory_map);
    schedule_init();
    pic_init();
    pic_timer_init();
    pic_rtc_init();
    pic_kbc_init();
    pic_set(0b11111000, 0b11101110); // master: slavePic, KBC, timer | slave: mouse

    IDT_init();
    M_LOAD_IDT();

    __asm__ volatile ("sti");

    task_1();
}


__attribute__((always_inline)) inline void set_segment_register(uint16_t cs, uint16_t ds, uint16_t ss) {
    uint64_t rsp;
    uint64_t rds = ds;
    __asm__ volatile ("mov rax, rsp": "=a"(rsp));

    struct InterruptFrameNoErrorCode frame = {
            (uint64_t)&&ret,
            cs,
            0x202,
            rsp,
            ss,
    };

    __asm__ volatile (
    "push %0 \n"
    "push %1 \n"
    "push %2 \n"
    "push %3 \n"
    "push %4 \n"
    "mov rax, %5 \n"
    "mov ds, ax \n"
    "iretq"
    :: "m"(frame.ss),"m"(frame.rsp),"m"(frame.rflags),"m"(frame.cs),"m"(frame.rip),"m"(rds)
    );
    ret:
    return;
}
