//
// Created by tia on 2020/03/16.
//

#include "graphics/output.h"

#include <std.h>
#include <stdint.h>
#include <bootloader/graphics_config.h>

void graphics_fill(GraphicsConfig *gc, uint32_t color) {
    uint64_t *buf = (uint64_t *) gc->framebuffer;
    uint64_t c = (uint64_t)color << 32 | color;
    for (uint64_t i = 0;
         i < gc->info.VerticalResolution * gc->info.HorizontalResolution / 2; i++) {
        *(buf++) = c;
    }
}

bool graphics_pixel(GraphicsConfig *gc, uint64_t x, uint64_t y, uint32_t color) {
    const uint64_t width = gc->info.HorizontalResolution;
    const uint64_t height = gc->info.VerticalResolution;

    if (x >= width || y >= height) return false;

    uint64_t p = x + (y * width);
    *((uint32_t*)gc->framebuffer + p) = color;

    return true;
}
