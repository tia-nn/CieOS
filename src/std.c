//
// Created by tia on 2020/03/16.
//

#include "std.h"

#include <stdint.h>


static const char NUMBER[] = "0123456789abcdefghijklmnopqrstuvwxyz";
static const char NUMBER_UPPERCASE[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void * KERNEL_LOADED_POINT;
void * ENTRY_POINT;

void halt() {
    __asm__ volatile ("hlt");
}

void hstop() {
    while (true) __asm__ volatile ("hlt");
}

void sleepms(uint64_t ms) {
    uint64_t now = TIMER_COUNT;
    while (now + ms > TIMER_COUNT) halt();
}


DIVMOD divmod(int64_t x, int64_t y) {
    DIVMOD ans;
    __asm__ volatile (
    "div rcx"
    : "=a"(ans.div), "=d"(ans.mod)
    : "a"(x), "d"(0), "c"(y)
    );
    return ans;
}

void itoa(uint64_t value, char *buffer, uint64_t buffer_size, uint64_t radix, uint32_t flags) {
    uint8_t is_minas = 0;

    if (flags & IS_SIGNED) {
        if ((int64_t) value < 0) {
            value = (int64_t) value * -1;
            is_minas = 1;
        }
    }

    if (flags & SET_SIGN || is_minas) {
        char sign = is_minas ? '-' : '+';
        *(buffer++) = sign;
        buffer_size--;
    }

    if (flags & SET_NULL_TERMINATE) {
        buffer_size--;
    }

    char const *charset;
    if (flags & UPPERCASE) {
        charset = NUMBER_UPPERCASE;
    } else {
        charset = NUMBER;
    }

    char tmp_buff[buffer_size];
    uint64_t i = buffer_size;
    uint64_t remain = value;

    while (remain && i) {
        DIVMOD dm = divmod(remain, radix);
        remain = dm.div;
        tmp_buff[--i] = charset[dm.mod];
    }

    if (i == buffer_size && flags & ZERO_IS_EMPTY && buffer_size) {
        tmp_buff[--i] = charset[0];
    }

    uint64_t j;
    if (!(flags & (FILL_SPACE | FILL_ZERO))) {
        for (j = 0; j < buffer_size - i; j++) {
            buffer[j] = tmp_buff[i + j];
        }
    } else {
        char fill;
        if (flags & FILL_ZERO) {
            fill = '0';
        } else if (flags & FILL_SPACE) {
            fill = ' ';
        }

        for (j = 0; j < i; j++) {
            buffer[j] = fill;
        }
        for (; j < buffer_size; j++) {
            buffer[j] = tmp_buff[j];
        }
    }
    if (flags & SET_NULL_TERMINATE) {
        buffer[j] = 0;
    }
}

bool strncmp(const char *a, const char *b, uint64_t n) {
    bool result = true;
    for (uint64_t i = 0; i < n; i ++) {
        result = result && (a[i] == b[i]);
    }
    return result;
}

bool strcmp(const char *a, const char *b) {
    bool result = true;
    for (uint64_t i = 0; ; i ++) {
        result = result && a[i] == b[i];
        if (!(a[i] && b[i])) return result;
    }
}

void strncpy(const char *src, char *dist, uint64_t n) {
    for (int64_t i = 0; i < n; i ++) {
        dist[i] = src[i];
    }
}

void strcpy(const char *src, char *dist) {
    uint64_t i;
    for (i = 0; src[i]; i ++) {
        dist[i] = src[i];
    }
    dist[i] = '\0';
}

void bool2str(char *dist, bool x) {
    if (x) {
        strcpy("true", dist);
    } else {
        strcpy("false", dist);
    }
}
