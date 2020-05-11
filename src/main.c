#include <main.h>
#include <std.h>
#include <bootloader/graphics_config.h>
#include <bootloader/memory_map.h>
#include <graphics/draw.h>
#include <graphics/print.h>
#include <memory_allocator/print.h>
#include <descriptor/segment.h>
#include <descriptor/interrupt.h>

__attribute__((always_inline)) void set_segment_register(uint16_t cs, uint16_t ds, uint16_t ss);

void _start(GraphicsConfig *graphics_config, MemoryMap *memoryMap) {
    draw_init(graphics_config);

    __asm__ volatile ("cli");

    GDT_init();
    M_LOAD_GDT();
    set_segment_register(8, 16, 16);

    IDT_init();
    M_LOAD_IDT();

    __asm__ volatile ("sti");

    print("GDT, IDT loaded, and segment selector set");

    draw_char('A', 16, 0, 0xffffff);
    draw_char('B', 16, 16, 0xffffff);
    draw_char('C', 16, 32, 0xffffff);

    puts("hogehoge");
    puts("fugafuga");
    puts("piyopiyo");

    print("hogehoge%", "fugafuga");

//    print_memory_map(memoryMap);

    volatile int div_by_zero = 10 / 0;

    while (true) hstop();
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
