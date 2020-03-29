//
// Created by tia on 2020/03/29.
//

#ifndef CIEOS_CONSOLE_H
#define CIEOS_CONSOLE_H

#include <std.h>
#include <stdint.h>
#include <bootloader/graphics_config.h>
#include <graphics/output.h>


typedef struct Console {
    GraphicsConfig *graphics;
    uint64_t width;
    uint64_t height;
    uint64_t x;
    uint64_t y;
    uint32_t background_color;
    uint32_t color;
} Console;

extern Console *g_console;

bool console_init(Console *console, GraphicsConfig *graphics);
uint64_t console_print(Console *console, const char *str);
void console_clear(Console *console);


#endif //CIEOS_CONSOLE_H
