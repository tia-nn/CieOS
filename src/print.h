//
// Created by tia on 2020/09/16.
//

#ifndef CIEOS_SRC_PRINT_H
#define CIEOS_SRC_PRINT_H

#include <stdint.h>
#include <stdbool.h>
#include "bootloader.h"

enum Color {
    BLACK = 0x000000u,
    DARKGRAY = 0x444444u,
    GRAY = 0x888888u,
    LIGHTGRAY = 0xccccccu,
    WHITE = 0xffffffu,

    RED = 0xff0000u,
    YELLOW = 0xffff00u,
    GREEN = 0x00ff00u,
    CYAN = 0x00ffffu,
    BLUE = 0x0000ffu,
    MAGENTA = 0xff00ffu,
};

void initialize_print(GraphicsConfig *gc);
bool draw_pixel(uint64_t x, uint64_t y, uint32_t color);
bool draw_char(uint64_t x, uint64_t y, uint8_t c, uint32_t color);
bool draw_char_bg(uint64_t x, uint64_t y, uint8_t c, uint32_t color, uint32_t bgColor);
void putchar(uint8_t c);
void print(const char *str);

#endif //CIEOS_SRC_PRINT_H
