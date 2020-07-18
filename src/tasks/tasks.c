//
// Created by tia on 2020/07/13.
//

#include "tasks/tasks.h"
#include <std.h>
#include <graphics/print.h>
#include <graphics/draw.h>

_Noreturn void task_1() {
    const uint64_t x = draw_get_width() - 8 * 9, y = 0;
    char buf[6];
    struct DateTime last;

    while (true) {
        if (*(uint64_t*)&last != *(uint64_t*)&RTC_DATA) {
            last = RTC_DATA;

            uint8_t hour_low = last.hour & 0x0fu;
            uint8_t hour_high = last.hour >> 4u;
            hour_low += 9;
            if (hour_low >= 10) {
                hour_low %= 10;
                hour_high = (hour_high + 1) % 3;
            }
            uint8_t hour = hour_low & 0x0fu | hour_high << 4u;

            itoa(hour, buf, 2, 16, FILL_ZERO);
            itoa(last.minute, buf + 2, 2, 16, FILL_ZERO);
            itoa(last.second, buf + 4, 2, 10, FILL_ZERO);
            draw_char_bg(buf[0], x, y, WHITE);
            draw_char_bg(buf[1], x + 8*1, y, WHITE);
            draw_char_bg(':', x + 8*2, y, WHITE);
            draw_char_bg(buf[2], x + 8*3, y, WHITE);
            draw_char_bg(buf[3], x + 8*4, y, WHITE);
            draw_char_bg(':', x + 8*5, y, WHITE);
            draw_char_bg(buf[4], x + 8*6, y, WHITE);
            draw_char_bg(buf[5], x + 8*7, y, WHITE);
        }
        halt();
    }
}

_Noreturn void task_2() {
    uint64_t last = 0;
    uint32_t color = RED;
    const uint64_t x = draw_get_width() - 8 - 16, y = 16;
    const char chars[] = {'-', '\\', '|', '/'};
    uint8_t i = 0;
    const uint32_t color_max = 0x1000000;
    while (true) {
        if (TIMER_COUNT > last + 100) {
            draw_char_bg(chars[i], x, y, color);
            i = (i + 1) % 4;
            last = TIMER_COUNT;
        }
        color = (color + 10) % color_max;
    }
}

_Noreturn void task_3() {
    const uint64_t x = draw_get_width() - 8 - 40, y = 32;
    char buf[2];
    uint8_t key_code;
    while (true) {
        if (ringbuf_read_dist(&KEYBOARD_BUFFER, &key_code)) {
            itoa(key_code, buf, 2, 16, FILL_ZERO);
            draw_char_bg('0', x + 0, y, WHITE);
            draw_char_bg('x', x + 8, y, WHITE);
            draw_char_bg(buf[0], x + 16, y, WHITE);
            draw_char_bg(buf[1], x + 24, y, WHITE);
        }
        else halt();
    }
}

void draw_mouse(int64_t x, int64_t y) {
    draw_pixel(x, y, WHITE);
    draw_pixel(x + 1, y, WHITE);
    draw_pixel(x, y + 1, WHITE);
    draw_pixel(x + 1, y + 1, WHITE);
}

_Noreturn void task_4() {
    int8_t codebuf[3];

    uint8_t button;
    int64_t x = 0;
    int64_t y = 0;
    draw_mouse(x, y);

    uint8_t code;
    uint8_t phase = 0;
    while (true) {
        if (ringbuf_read_dist(&MOUSE_BUFFER, &code)) {
            switch (phase) {
                case 0:
                    if (code == 0xfa) phase = 1;  // 最初の0xfaを読み飛ばす
                    break;
                case 1:
                    codebuf[0] = code;
                    phase = 2;
                    break;
                case 2:
                    codebuf[1] = code;
                    phase = 3;
                    break;
                case 3:
                    codebuf[2] = code;
                    int8_t a = codebuf[1], b = codebuf[2];
                    button = codebuf[0] & 0x07;
                    x += a;
                    y -= b;
                    draw_mouse(x, y);
                    phase = 1;
                    break;
                default:
                    break;
            }
        }
        else halt();
    }
}
