#include <main.h>
#include <std.h>
#include <bootloader/graphics_config.h>
#include <graphics/output.h>
#include <graphics/console.h>


void _start(GraphicsConfig *graphics_config) {
    gc_global_init(graphics_config);
    Console _console;
    Console *console = &_console;
    console_init(console, graphics_config);

    draw_fill(0x000000);

    draw_char('A', 16, 0, 0xffffff);
    draw_char('B', 16, 16, 0xffffff);
    draw_char('C', 16, 32, 0xffffff);

    console_print(console, "A");
    console_print(console, "B");
    console_print(console, "C");

    while (true) hstop();
}