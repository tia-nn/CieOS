#include <main.h>
#include <std.h>
#include <bootloader/graphics_config.h>
#include <graphics/output.h>

void _start(GraphicsConfig *graphics_config) {
    uint64_t color = 0x000001;

    graphics_fill(graphics_config, 0xaaeeff);
    for (uint64_t i = 0; i < graphics_config->info.VerticalResolution; i ++) {
        graphics_pixel(graphics_config, i, i, ~color);
    }

    while (true) hstop();
}