//
// Created by tia on 2020/09/16.
//

#include <stdint.h>
#include <stdbool.h>
#include "bootloader.h"
#include "initialize.h"
#include "print.h"
#include "tools.h"

_Noreturn void
_start(GraphicsConfig *graphics_config, MemoryMap *memory_map, void *acpi_table, void *code_top, void *entrypoint) {
    __asm__ volatile ("cli");
    KERNEL_LOADED_POINT = code_top;
    ENTRY_POINT = entrypoint;
    initialize(graphics_config, memory_map);
    __asm__ volatile ("sti");
    print("initialized\n");

    uint64_t timer_next = 100;
    while (true) {
        if (timer_next < TIMER_COUNT) {
            timer_next += 100;
            print("timer 100 counts\n");
        }
        __asm__ volatile ("hlt");
    }
}
