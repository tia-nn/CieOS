//
// Created by tia on 2020/03/29.
//

#include <stdint.h>
#include <std.h>
#include <bootloader/graphics_config.h>
#include <graphics/output.h>
#include "graphics/console.h"


Console *g_console;


bool console_init(Console *console, GraphicsConfig *graphics) {
    console->graphics = graphics;
    console->width = graphics->info.HorizontalResolution / 8;
    console->height = graphics->info.VerticalResolution / 16;
    console->x = 0;
    console->y = 0;
    console->background_color = 0x333333;
    console->color = 0xffffff;
//    console_clear(console);
    return true;
}

bool console_newline(Console *console) {
    console->x = 0;
    if (console->y == console->height - 1) {
        gc_scroll(console->graphics, 16, console->background_color);
    } else {
        console->y += 1;
    }
    return true;
}

uint64_t console_print(Console *console, const char *str) {
    uint64_t i = 0;
    while (str[i] != 0) {
        char c = str[i];
        if (c == '\n') {
            console_newline(console);
        } else if (c == '\r') {
            console->x = 0;
        } else {
            gc_draw_char(console->graphics, c, console->x * 8, console->y * 16, console->color);
        }
        i ++;
    }
    console_newline(console);
}
