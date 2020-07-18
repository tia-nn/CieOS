//
// Created by tia on 2020/07/18.
//

#include <std.h>
#include <interrupt_handler.h>
#include <pic.h>
#include <graphics/print.h>

struct DateTime RTC_DATA;

#define rtc_in_out(addr, dist) __asm__ volatile (\
    "out 0x70, al\n"\
    "in al, 0x71\n"\
    : "=a"(dist) : "a"(addr)\
)

__attribute__((interrupt))
void int_40_handler(union InterruptFrame *frame) {
    rtc_in_out(9, RTC_DATA.year);
    rtc_in_out(8, RTC_DATA.month);
    rtc_in_out(7, RTC_DATA.day);
    rtc_in_out(4, RTC_DATA.hour);
    rtc_in_out(2, RTC_DATA.minute);
    rtc_in_out(0, RTC_DATA.second);

    __asm__ volatile (
            "out 0x70, al \n"
            "in al, 0x71"
            :: "a"(0x0c));
    PIC_SLAVE_EOI();
    PIC_MASTER_EOI();
}

