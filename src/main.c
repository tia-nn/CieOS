#include <main.h>
#include <std.h>
#include <bootloader/graphics_config.h>
#include <graphics/output.h>


void _start(GraphicsConfig *graphics_config) {
    gc_global_init(graphics_config);

    uint64_t color = 0xaaeeff;

    gc_draw_fill(graphics_config, color);
    for (uint64_t i = 0; i < graphics_config->info.VerticalResolution; i ++) {
        gc_draw_pixel(graphics_config, i, i, ~color);
    }
    gc_draw_char(graphics_config, 'C', 3, 1, 0x333333);

    draw_char('B', 10, 15, 0x555555);

    while (true) hstop();
}