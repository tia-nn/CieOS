//
// Created by tia on 2020/05/06.
//

#ifndef CIEOS_INCLUDE_GRAPHICS_PRINT_H
#define CIEOS_INCLUDE_GRAPHICS_PRINT_H


extern const uint32_t gPRINTCOLOR;

void puts(const char *str);
void puts_right(const char *str);
//__attribute__((no_caller_saved_registers))
void print(const char *format, ...);
void print_right(const char *format, ...);

#endif //CIEOS_INCLUDE_GRAPHICS_PRINT_H
