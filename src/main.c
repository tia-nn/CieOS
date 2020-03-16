#include <main.h>
#include <std.h>
#include <bootloader/graphics_config.h>
#include <graphics/output.h>

void _start(GraphicsConfig *graphics_config) {
    uint64_t color = 0xaaeeff;

    graphics_fill(graphics_config, color);
    for (uint64_t i = 0; i < graphics_config->info.VerticalResolution; i ++) {
        graphics_pixel(graphics_config, i, i, ~color);
    }
    graphics_char(graphics_config, 'C', 3, 1, 0x333333);

    while (true) hstop();
}