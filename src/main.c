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
//
//    print("GDT, IDT loaded, and segment selector set");
//
//    draw_char('A', 16, 0, 0xffffff);
//    draw_char('B', 16, 16, 0xffffff);
//    draw_char('C', 16, 32, 0xffffff);
//
//    puts("hogehoge");
//    puts("fugafuga");
//    puts("piyopiyo");
//
//    print("hogehoge%", "fugafuga");

//    print_memory_map(memoryMap);

//    volatile int div_by_zero = 10 / 0;

//    uint64_t rcx_1, rcx_2, rax_1, rax_2, rdx_1, rdx_2;
//
//    __asm__ volatile ("mov rax, rsp": "=a"(rax_1));
//    __asm__ volatile ("": "=d"(rdx_1));
//    __asm__ volatile ("": "=c"(rcx_1));
//    __asm__ volatile ("int 32");
////    print("print_test");
//    __asm__ volatile ("mov rax, rsp": "=a"(rax_2));
//    __asm__ volatile ("": "=d"(rdx_2));
//    __asm__ volatile ("": "=c"(rcx_2));
//
//    char buf[17], buf_2[17];
//
//    itoa(rax_1, buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
//    itoa(rax_2, buf_2, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
//
//    print("before : %", buf);
//    print("after :  %", buf_2);
//
//    itoa(rdx_1, buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
//    itoa(rdx_2, buf_2, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
//
//    print("before : %", buf);
//    print("after :  %", buf_2);
//
//    itoa(rcx_1, buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
//    itoa(rcx_2, buf_2, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
//
//    print("before : %", buf);
//    print("after :  %", buf_2);

//    __asm__ volatile ("int 13");



    uint64_t last = TIMER_COUNT;
    uint64_t i = 0;
    while (true) {
        if (last + 10 < TIMER_COUNT) {
            last = TIMER_COUNT;

//        __asm__ volatile ("mov rax, rsp": "=a"(rax_2));
//        itoa(rax_1, buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
//        itoa(rax_2, buf_2, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
//
//        print("before : %", buf);
//        print("after :  %", buf_2);

            print("100 count");
        }

//        draw_pixel(i, i, WHITE);
//        draw_char('A' + i, i, i, GRAY);
//        i ++;
        halt();
    };
    hstop();
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
