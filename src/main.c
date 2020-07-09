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
#include <interrupt_handler.h>
#include <control_registers.h>
#include <paging.h>
#include <file/read_hdd.h>

__attribute__((always_inline)) void set_segment_register(uint16_t cs, uint16_t ds, uint16_t ss);

void _start(GraphicsConfig *graphics_config, MemoryMap *memory_map, void *acpi_table, void* code_top, void *entrypoint) {
    draw_init(graphics_config);

    KERNEL_LOADED_POINT = code_top;
    ENTRY_POINT = entrypoint;

    __asm__ volatile ("cli");

    GDT_init();
    M_LOAD_GDT();
    set_segment_register(8, 16, 16);

    schedule_init();
    pic_init();
    pic_timer_init();
    pic_set(0b11111000, 0b11111111); // master: slavePic, KBC, timer | slave:

    IDT_init();
    M_LOAD_IDT();
    init_paging();

//    print_memory_map(memory_map);

    uint64_t last = TIMER_COUNT;
    uint64_t i = 0;
    uint64_t _ = 0;
    char buf[65];

    struct CR0 cr0;
    struct CR3 cr3;
    uint64_t cr4;

    __asm__ volatile ("mov rax, cr0" : "=a"(cr0));
    __asm__ volatile ("mov rax, cr3" : "=a"(cr3));
    __asm__ volatile ("mov rax, cr4" : "=a"(cr4));

    struct PageMapLevel4Entry *pml4;
    pml4 = (void *)((uint64_t)cr3.PML4_addr << 12u);

    for (int i = 0; i < 512; i ++) {
        PageMapLevel4[i] = pml4[i];
    }

    cr3.PML4_addr = ((uint64_t)PageMapLevel4) >> 12u;

//    __asm__ volatile ("mov cr4, rax" : : "a"(cr4));
    __asm__ volatile ("mov cr3, rax" : : "a"(cr3));
//    __asm__ volatile ("mov cr0, rax" : : "a"(cr0));

    __asm__ volatile ("sti");

    uint8_t hdd_buf[512];
//    uint64_t lba = 0;
//    read_lba(lba, 1);
    read_hdd(hdd_buf, 1, 1);
    hdd_buf[9] = 0;
    print(hdd_buf);
//    read_lba(100, 1);

    while (true) {
        if (last + 1000 < TIMER_COUNT) {
            last = TIMER_COUNT;
            itoa(last, buf, 17, 10, SET_NULL_TERMINATE);
            print_right("timer count %", buf);
        }
        halt();
    }
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
