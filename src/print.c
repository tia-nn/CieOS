//
// Created by tia on 2020/09/16.
//

#include "print.h"
#include <stdint.h>
#include <stdbool.h>
#include "hankaku.h"
#include "tools.h"
#include "bootloader.h"

GraphicsConfig *GC;
// ------ console ------
uint32_t CH_COLOR = LIGHTGRAY;
uint32_t BG_COLOR = BLACK;
uint64_t COL = 0;
uint64_t ROW = 0;
uint64_t SOFT_WRAP_COUNT = 0;
uint64_t MAX_COL;
uint64_t MAX_ROW;

uint64_t PRINT_IN_USE = 0;

#define FRAMEBUFFER_IN_USE 0
#define POSITION_IN_USE 1

void initialize_print(GraphicsConfig *gc) {
    GC = gc;
    MAX_COL = gc->info.HorizontalResolution / 8;
    MAX_ROW = gc->info.VerticalResolution / 16;
}

bool draw_pixel(uint64_t x, uint64_t y, uint32_t color) {
    const uint64_t width = GC->info.HorizontalResolution;
    const uint64_t height = GC->info.VerticalResolution;

    if (x >= width || y >= height) return false;

    uint32_t *frame_buffer = (uint32_t *) GC->framebuffer;
    uint64_t p = x + (y * width);
    uint32_t *dist = frame_buffer + p;

    test_and_set(&PRINT_IN_USE, FRAMEBUFFER_IN_USE);
    *dist = color;
    BIT_ARR_ACCESS(PRINT_IN_USE, FRAMEBUFFER_IN_USE) = 0;

    return true;
}

bool draw_2pixel(uint64_t x, uint64_t y, uint64_t dot2) {  // 左右逆になる (little endian)
    const uint64_t width = GC->info.HorizontalResolution;
    const uint64_t height = GC->info.VerticalResolution;

    if (x + 1 >= width || y >= height) return false;

    uint32_t *frame_buffer = (uint32_t *) GC->framebuffer;
    uint64_t p = x + (y * width);
    uint64_t *dist = (uint64_t *) (frame_buffer + p);

    test_and_set(&PRINT_IN_USE, FRAMEBUFFER_IN_USE);
    *dist = dot2;
    BIT_ARR_ACCESS(PRINT_IN_USE, FRAMEBUFFER_IN_USE) = 0;

    return true;
}

bool draw_char(uint64_t x, uint64_t y, uint8_t c, uint32_t color) {
    uint8_t *font = FONT[c];

    for (uint8_t i = 0; i < 16; i++) {
        for (uint8_t j = 0; j < 8; j++) {
            uint8_t dot = font[i] & (0b10000000u >> j);
            if (dot) {
                if (!draw_pixel(x + j, y + i, color))
                    return false;
            }
        }
    }

    return true;
}

bool draw_char_bg(uint64_t x, uint64_t y, uint8_t c, uint32_t color, uint32_t bgColor) {
    uint8_t *font = FONT[c];

    for (uint64_t i = 0; i < 16; i++) {
        uint8_t line = font[i];
        for (uint64_t j = 0; j < 8; j += 2) {
            uint64_t dot2;
            DOUBLEWORD_ACCESS(dot2).low = (line & 0b10000000u) ? color : bgColor;
            line <<= 1u;
            DOUBLEWORD_ACCESS(dot2).high = (line & 0b10000000u) ? color : bgColor;
            if (!draw_2pixel(x + j, y + i, dot2))
                return false;
            line <<= 1u;
        }
    }

    return true;
}

// ------ console ------

void putchar(uint8_t c) {
    test_and_set(&PRINT_IN_USE, POSITION_IN_USE);

    uint64_t last_col = COL;
    uint64_t last_row = ROW;
    bool backspace = false;
    bool backspace_softwrapped = false;
    bool put = false;

    if (c == '\n') {
        COL = 0;
        SOFT_WRAP_COUNT = 0;
        ROW = (ROW + 1) % MAX_ROW;
    } else if (c == '\r') {
        COL = 0;
        if (ROW < SOFT_WRAP_COUNT) {
            ROW = MAX_ROW - (SOFT_WRAP_COUNT % MAX_ROW - ROW);
        } else {
            ROW -= SOFT_WRAP_COUNT;
        }
    } else if (c == '\b') {
        if (COL) {
            COL--;
            backspace = true;
        } else if (SOFT_WRAP_COUNT) {
            COL = MAX_COL - 1;
            ROW = (ROW) ? ROW - 1 : MAX_ROW - 1;
            SOFT_WRAP_COUNT -= 1;
            backspace_softwrapped = true;
        }
    } else {
        COL = COL + 1;
        if (COL == MAX_COL) {
            COL = 0;
            ROW = (ROW + 1) % MAX_ROW;
            SOFT_WRAP_COUNT ++;
        }
        put = true;
    }

    BIT_ARR_ACCESS(PRINT_IN_USE, POSITION_IN_USE) = 0;

    if (backspace) {
        last_col --;
        c = ' ';
        put = true;
    } else if (backspace_softwrapped) {
        last_col = MAX_COL - 1;
        last_row = (last_row) ? last_row - 1 : MAX_ROW - 1;
        c = ' ';
        put = true;
    }

    if (put) {
        draw_char_bg(last_col * 8, last_row * 16, c, CH_COLOR, BG_COLOR);
    }
}

void print(const char *str) {
    for (uint64_t i = 0; str[i]; i ++) {
        putchar(str[i]);
    }
}
