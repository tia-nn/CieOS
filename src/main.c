//
// Created by tia on 2020/09/16.
//

#include <stdint.h>
#include <stdbool.h>
#include "bootloader.h"
#include "initialize.h"
#include "print.h"

_Noreturn void _start(GraphicsConfig *graphics_config, MemoryMap *memory_map, void *acpi_table, void* code_top, void *entrypoint) {
    __asm__ volatile ("cli");

    initialize(graphics_config);

    for (uint64_t i = 0; i < graphics_config->info.VerticalResolution; i ++) {
        for (uint64_t j = 0; j < graphics_config->info.HorizontalResolution; j ++) {
            draw_pixel(j, i, BLACK);
        }
    }

    print("hogehoge\n");

    __asm__ volatile ("sti");

    volatile a = 0;
    a / 0;

    __asm__ volatile ("int 0");

    while (true) __asm__ volatile ("hlt");
}
