//
// Created by tia on 2020/03/16.
//

#ifndef CIEOS_OUTPUT_H
#define CIEOS_OUTPUT_H

#include <std.h>
#include <stdint.h>
#include <bootloader/graphics_config.h>


extern GraphicsConfig *g_graphics_config;

bool gc_global_init(GraphicsConfig *gc);

void gc_draw_fill(GraphicsConfig *gc, uint32_t color);
bool gc_draw_pixel(GraphicsConfig *gc, uint64_t x, uint64_t y, uint32_t color);
bool gc_draw_char(GraphicsConfig *gc, char c, uint64_t x, uint64_t y, uint32_t color);
bool gc_scroll(GraphicsConfig *gc, uint64_t scroll_height, uint32_t color);

void draw_fill(uint32_t color);
bool draw_pixel(uint64_t x, uint64_t y, uint32_t color);
bool draw_char(char c, uint64_t x, uint64_t y, uint32_t color);

#endif //CIEOS_OUTPUT_H
