//
// Created by tia on 2020/05/11.
//

#include <pic.h>
#include <stdint.h>

void pic_init() {
    outp(0x20, 0x11);
    outp(0x21, 0x20);
    outp(0x21, 0x04);
    outp(0x21, 0x05);
    outp(0x21, 0xff);

    outp(0xa0, 0x11);
    outp(0xa1, 0x28);
    outp(0xa1, 0x02);
    outp(0xa1, 0x01);
    outp(0xa1, 0xff);
}

void pic_set(uint8_t master, uint8_t slave) {
    outp_v(0x21, master);
    outp_v(0xa1, slave);
}

void pic_timer_init() {
    outp(0x43, 0b00110100);

//    outp(0x40, 0x9c);  // 1193182 Hz / 100 = 0x2e9c (0.001s)
//    outp(0x40, 0x2e);

    outp(0x40, 0xa9);  // 1193182 Hz / 1000 = 0x04a9 (0.0001s)
    outp(0x40, 0x04);
}

void kbc_send_wait() {
    uint8_t status;
    do {
        __asm__ volatile ("in al, 0x64" : "=a"(status));
    } while (status & 0x02);

}

void pic_kbc_init() {
    kbc_send_wait();
    __asm__ volatile ("out 0x64, al" : : "a"(0xd4));
    kbc_send_wait();
    __asm__ volatile ("out 0x60, al" : : "a"(0xf4));
}
