//
// Created by tia on 2020/03/16.
//

#ifndef CIEOS_INCLUDE_GRAPHICS_DRAW_H
#define CIEOS_INCLUDE_GRAPHICS_DRAW_H

#include <std.h>
#include <stdint.h>
#include <bootloader/graphics_config.h>

enum Color {
    BLACK = 0x000000,
    DARKGRAY = 0x444444,
    GRAY = 0x888888,
    LIGHTGRAY = 0xcccccc,
    WHITE = 0xffffff
};

extern const uint32_t gBGCOLOR;

bool draw_init(GraphicsConfig *gc);

void draw_fill(uint32_t color);
// DO NOT USE.
//void draw_scroll(uint64_t scroll_height, uint32_t color);
bool draw_pixel(uint64_t x, uint64_t y, uint32_t color);
bool draw_char(char c, uint64_t x, uint64_t y, uint32_t color);

uint64_t draw_get_height();
uint64_t draw_get_width();

#endif //CIEOS_INCLUDE_GRAPHICS_DRAW_H
