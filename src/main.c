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
    pic_kbc_init();
    pic_set(0b11111000, 0b11101111); // master: slavePic, KBC, timer | slave: mouse

    IDT_init();
    M_LOAD_IDT();

    __asm__ volatile ("sti");

    task_1();
}


__attribute__((always_inline)) inline void set_segment_register(uint16_t cs, uint16_t ds, uint16_t ss) {

    __asm__ volatile (
    "mov ax, %0 \n"
    "mov ds, ax \n"
    "mov ax, %1 \n"
    "mov ss, ax"
    : : "m"(ds), "m"(ss)
    );

    void *a = &&ret;

    __asm__ volatile (
    "movzx eax, %0 \n"
    "push rax \n"
    "lea rax, +8[rsp] \n"
    "push rax \n"
    "pushfq \n"
    "movzx eax, %1 \n"
    "push rax \n"
    "push %2 \n"
    "iretq"
    : : "m"(ss), "m"(cs), "m"(a)
    );
    ret:
    return;
}
