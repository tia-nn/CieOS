//
// Created by tia on 2020/05/06.
//

#include <graphics/draw.h>
#include <std.h>
#include <stdint.h>
#include <graphics/print.h>
#include <zconf.h>


const uint32_t gPRINTCOLOR = LIGHTGRAY;


uint64_t put(const char *str, uint64_t col) {
    for (uint64_t i = 0; str[i]; i ++, col ++) {
        if (str[i] == '\n') {
            col = 0;
            draw_scroll(16, gBGCOLOR);
        } else if (str[i] == '\r') {
            col = 0;
        } else {
            draw_char(str[i], col * 8, draw_get_height() - 16 - 1, gPRINTCOLOR);
        }
    }
    return col;
}

void puts(const char *str) {
    put(str, 0);
    draw_scroll(16, gBGCOLOR);
}

void print(const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    uint64_t col = 0;
    for (uint64_t i = 0; format[i]; i ++, col ++) {
        if (format[i] == '\n') {
            col = 0;
            draw_scroll(16, gBGCOLOR);
        } else if (format[i] == '\r') {
            col = 0;
        } else if (format[i] == '%') {
            col = put(va_arg(ap, char *), col);
        } else {
            draw_char(format[i], col * 8, draw_get_height() - 16 - 1, gPRINTCOLOR);
        }
    }
    draw_scroll(16, gBGCOLOR);
}
