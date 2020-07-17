//
// Created by tia on 2020/07/13.
//

#include "tasks/tasks.h"
#include <std.h>
#include <graphics/print.h>
#include <graphics/draw.h>

void task_1() {
    uint64_t last = TIMER_COUNT;
    uint64_t i = 0;
    uint64_t _ = 0;
    char buf[65];

    while (true) {
        if (last + 1000 < TIMER_COUNT) {
            last = TIMER_COUNT;
            itoa(last, buf, 17, 10, SET_NULL_TERMINATE);
            print_right("timer count %", buf);
        }
        halt();
    }
}

void task_2() {
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

void task_3() {
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


void task_4() {
    const uint64_t x = draw_get_width() - 8 - 40, y = 48;
    char buf[2];
    uint8_t key_code;
    while (true) {
        if (ringbuf_read_dist(&MOUSE_BUFFER, &key_code)) {
            itoa(key_code, buf, 2, 16, FILL_ZERO);
            draw_char_bg('0', x + 0, y, WHITE);
            draw_char_bg('x', x + 8, y, WHITE);
            draw_char_bg(buf[0], x + 16, y, WHITE);
            draw_char_bg(buf[1], x + 24, y, WHITE);
        }
        else halt();
    }
}
