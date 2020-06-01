#include <main.h>
#include <std.h>
#include <bootloader/graphics_config.h>
#include <bootloader/memory_map.h>
#include <graphics/draw.h>
#include <graphics/print.h>
#include <memory_allocator/print.h>
#include <descriptor/segment.h>
#include <descriptor/interrupt.h>
#include <pic.h>

void task_2();
__attribute__((always_inline)) void set_segment_register(uint16_t cs, uint16_t ds, uint16_t ss);

void _start(GraphicsConfig *graphics_config, MemoryMap *memory_map, void *acpi_table, void* code_top, void *entrypoint) {
    draw_init(graphics_config);

    KERNEL_LOADED_POINT = code_top;
    ENTRY_POINT = entrypoint;

//    char top_buf[17];
//    itoa((uint64_t)code_top, top_buf, 17, 16, SET_NULL_TERMINATE|FILL_ZERO);
//    print("top: %", top_buf);

    __asm__ volatile ("cli");

    GDT_init();
    M_LOAD_GDT();
    set_segment_register(8, 16, 16);

    pic_init();
    pic_timer_init();
    pic_set(0b11111000, 0b11111111); // master: slavePic, KBC, timer | slave:

    IDT_init();
    M_LOAD_IDT();

    __asm__ volatile ("sti");

    task_2();

    uint64_t last = TIMER_COUNT;
    uint64_t i = 0;
    while (true) {
        if (last + 10 < TIMER_COUNT) {
            last = TIMER_COUNT;
            print("100 count");
        }
        halt();
    }
}


void task_2() {
    uint64_t last = 0;
    uint32_t color = 0;
    static const uint32_t color_max = 0x1000000;
    while (true) {
        if (TIMER_COUNT != last) {
            draw_char('O', draw_get_width() - 8, draw_get_height() - 16, color);
            color = (color + 1) % color_max;
            last = TIMER_COUNT;
        }
        halt();
    };
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
