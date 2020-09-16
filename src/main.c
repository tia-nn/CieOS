//
// Created by tia on 2020/09/16.
//

#include <stdint.h>
#include <stdbool.h>
#include "bootloader.h"

_Noreturn void _start(GraphicsConfig *graphics_config, MemoryMap *memory_map, void *acpi_table, void* code_top, void *entrypoint) {
    for (uint64_t i = 0; i < graphics_config->info.VerticalResolution * graphics_config->info.HorizontalResolution; i ++) {
        ((uint32_t*)graphics_config->framebuffer)[i] = 0xaaaaaa;
    }

    while (true) __asm__ volatile ("hlt");
}
