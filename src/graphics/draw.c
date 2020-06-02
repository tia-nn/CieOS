//
// Created by tia on 2020/03/16.
//

#include "graphics/draw.h"

#include <std.h>
#include <stdint.h>
#include <bootloader/graphics_config.h>
#include <font/hankaku.h>

GraphicsConfig *g_graphics_config;

const uint32_t gBGCOLOR = BLACK;


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
            } else {
                ret |= !gc_draw_pixel(gc, x + j, y + i, gBGCOLOR);
            }
        }
    }

    return !ret;
}

void gc_draw_scroll(GraphicsConfig *gc, uint64_t scroll_height, uint32_t color) {
    uint64_t diff = scroll_height * gc->info.HorizontalResolution;
    uint64_t size = gc->info.HorizontalResolution * gc->info.VerticalResolution;
    uint64_t i;
    for (i = 0; i < size; i ++) {
        ((uint32_t*)gc->framebuffer)[i] = ((uint32_t*)gc->framebuffer)[i + diff];
    }
    for (; i < size; i ++) {
        ((uint32_t*)gc->framebuffer)[i] = color;
    }
}


void draw_fill(uint32_t color) {
    gc_draw_fill(g_graphics_config, color);
}

void draw_scroll(uint64_t scroll_height, uint32_t color) {
    gc_draw_scroll(g_graphics_config, scroll_height, color);
}

bool draw_pixel(uint64_t x, uint64_t y, uint32_t color) {
    return gc_draw_pixel(g_graphics_config, x, y, color);
}

bool draw_char(char c, uint64_t x, uint64_t y, uint32_t color) {
    return gc_draw_char(g_graphics_config, c, x, y, color);
}

uint64_t draw_get_height() {
    return g_graphics_config->info.VerticalResolution;
}

uint64_t draw_get_width() {
    return g_graphics_config->info.HorizontalResolution;
}

bool draw_init(GraphicsConfig *gc) {
    g_graphics_config = gc;
    gc_draw_fill(gc, gBGCOLOR);
    return true;
}