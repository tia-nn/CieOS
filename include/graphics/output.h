//
// Created by tia on 2020/03/16.
//

#ifndef CIEOS_OUTPUT_H
#define CIEOS_OUTPUT_H

#include <std.h>
#include <stdint.h>
#include <bootloader/graphics_config.h>


void graphics_fill(GraphicsConfig *gc, uint32_t color);
bool graphics_pixel(GraphicsConfig *gc, uint64_t x, uint64_t y, uint32_t color);
bool graphics_char(GraphicsConfig *gc, char c, uint64_t x, uint64_t y, uint32_t color);

#endif //CIEOS_OUTPUT_H
