#include <main.h>
#include <std.h>
#include <bootloader/graphics_config.h>

void _start(GraphicsConfig *graphics_config) {
    uint64_t color = 0x000001;

    while (true) {
        uint64_t *buf = (uint64_t *) graphics_config->framebuffer;
        for (uint64_t i = 0;
             i < graphics_config->info.VerticalResolution * graphics_config->info.HorizontalResolution / 2; i++) {
            *(buf++) = color;
        }
        color *= 3;
        if (!color) {
            color = 1;
        }
    }
}