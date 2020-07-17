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

struct BitAccess FRAMEBUFFER_IN_USE;


void draw_fill(uint32_t color) {
    uint64_t *buf = (uint64_t *) g_graphics_config->framebuffer;
    uint64_t c = (uint64_t)color << 32 | color;
    for (uint64_t i = 0;
            i < g_graphics_config->info.VerticalResolution * g_graphics_config->info.HorizontalResolution / 2; i++) {

        test_and_set((uint64_t *)&FRAMEBUFFER_IN_USE, 0);
        *(buf++) = c;
        FRAMEBUFFER_IN_USE.bit_0 = 0;
    }
}

bool draw_pixel(uint64_t x, uint64_t y, uint32_t color) {
    const uint64_t width = g_graphics_config->info.HorizontalResolution;
    const uint64_t height = g_graphics_config->info.VerticalResolution;
    uint32_t *frame_buffer = (uint32_t*)g_graphics_config->framebuffer;

    if (x >= width || y >= height) return false;

    uint64_t p = x + (y * width);

    test_and_set((uint64_t *)&FRAMEBUFFER_IN_USE, 0);
    frame_buffer[p] = color;
    FRAMEBUFFER_IN_USE.bit_0 = 0;

    return true;
}

bool draw_char(char c, uint64_t x, uint64_t y, uint32_t color) {
    uint8_t *f = FONT[c];
    bool ret = false;

    for (uint64_t i = 0; i < 16; i++) {
        for (uint64_t j = 0; j < 8; j++) {
            uint8_t a = f[i] & (0b10000000u >> j);
            if (a) {
                ret |= !draw_pixel(x + j, y + i, color);
            }
        }
    }

    return !ret;
}

bool draw_char_bg(char c, uint64_t x, uint64_t y, uint32_t color) {
    uint8_t *f = FONT[c];
    bool ret = false;

    for (uint64_t i = 0; i < 16; i++) {
        for (uint64_t j = 0; j < 8; j++) {
            uint8_t a = f[i] & (0b10000000u >> j);
            if (a) {
                ret |= !draw_pixel(x + j, y + i, color);
            } else {
                ret |= !draw_pixel(x + j, y + i, gBGCOLOR);
            }
        }
    }

    return !ret;
}

// tools

uint64_t draw_get_height() {
    return g_graphics_config->info.VerticalResolution;
}

uint64_t draw_get_width() {
    return g_graphics_config->info.HorizontalResolution;
}

bool draw_init(GraphicsConfig *gc) {
    g_graphics_config = gc;
    draw_fill(gBGCOLOR);
    return true;
}