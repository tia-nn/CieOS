//
// Created by tia on 2020/03/16.
//

#include "graphics/output.h"

#include <std.h>
#include <stdint.h>
#include <bootloader/graphics_config.h>
#include <font/hankaku.h>

GraphicsConfig *g_graphics_config;


bool gc_global_init(GraphicsConfig *gc) {
    g_graphics_config = gc;
    draw_fill(0x000000);
    return true;
}

void gc_draw_fill(GraphicsConfig *gc, uint32_t color) {
    uint64_t *buf = (uint64_t *) gc->framebuffer;
    uint64_t c = (uint64_t)color << 32 | color;
    for (uint64_t i = 0;
         i < gc->info.VerticalResolution * gc->info.HorizontalResolution / 2; i++) {
        *(buf++) = c;
    }
}

bool gc_draw_pixel(GraphicsConfig *gc, uint64_t x, uint64_t y, uint32_t color) {
    const uint64_t width = gc->info.HorizontalResolution;
    const uint64_t height = gc->info.VerticalResolution;

    if (x >= width || y >= height) return false;

    uint64_t p = x + (y * width);
    *((uint32_t*)gc->framebuffer + p) = color;

    return true;
}

bool gc_draw_char(GraphicsConfig *gc, char c, uint64_t x, uint64_t y, uint32_t color) {
    uint8_t *f = FONT[c];
    bool ret = false;

    for (uint64_t i = 0; i < 16; i++) {
        for (uint64_t j = 0; j < 8; j++) {
            uint8_t a = f[i] & (0b10000000u >> j);
            if (a) {
                ret |= !gc_draw_pixel(gc, x + j, y + i, color);
            }
        }
    }

    return !ret;
}


void draw_fill(uint32_t color) {
    gc_draw_fill(g_graphics_config, color);
}

bool draw_pixel(uint64_t x, uint64_t y, uint32_t color) {
    return gc_draw_pixel(g_graphics_config, x, y, color);
}

bool draw_char(char c, uint64_t x, uint64_t y, uint32_t color) {
    return gc_draw_char(g_graphics_config, c, x, y, color);
}
