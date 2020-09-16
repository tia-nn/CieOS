import sys

stdout = sys.stdout

# ------ font ------

code = open('hankaku.txt').read()
dist_c = open('../src/hankaku.c', 'w')
dist_h = open('../src/hankaku.h', 'w')
sys.stdout = dist_c

fonts = code.split('\n\n')
print('#include <stdint.h>')
print('uint8_t FONT[0x100][16] = ', end='')

chars = []

for i in fonts:
    a = i.split('\n')
    char = []
    for j in a[1:]:
        char.append('        0b' + j.replace('.', '0').replace('*', '1'))
    chars.append(char)

p_chars = []
for i in chars:
    p_chars.append('\n' + ',\n'.join(i) + '\n')

print('{')
print('    {' + '    }, {'.join(p_chars) + '    }')
print('};')

dist_h.write('''
#ifndef __HANKAKU_FONT_H
#define __HANKAKU_FONT_H
#include <stdint.h>
extern uint8_t FONT[0x100][16];
#endif
''')

dist_c.close()
dist_h.close()

# ------ default interrupt handler ------

info = [
           '0 - Divide Error Exception (#DE)',
           '1 - Debug Exception (#DB)',
           '2 - NMI Interrupt',
           '3 - Breakpoint Exception (#BP)',
           '4 - Overflow Exception (#OF)',
           '5 - BOUND Range Exceeded Exception (#BR)',
           '6 - Invalid Opcode Exception (#UD)',
           '7 - Device Not Available Exception (#NM)',
           '8 - Double Fault Exception (#DF)',
           '9 - Coprocessor Segment Overrun',
           '10 - Invalid TSS Exception (#TS)',
           '11 - Segment Not Present (#NP)',
           '12 - Stack Fault Exception (#SS)',
           '13 - General Protection Exception (#GP)',
           '14 - Page-Fault Exception (#PF)',
           '15 - default handler (intel reserved vector)',
           '16 - x87 FPU Floating-Point Error (#MF)',
           '17 - Alignment Check Exception (#AC)',
           '18 - Machine-Check Exception (#MC)',
           '19 - SIMD Floating-Point Exception (#XM)',
           '20 - Virtualization Exception (#VE)',
           '21 - Control Protection Exception (#CP)',
       ] + [
           '22 - default handler (intel reserved vector)',
           '23 - default handler (intel reserved vector)',
           '24 - default handler (intel reserved vector)',
           '25 - default handler (intel reserved vector)',
           '26 - default handler (intel reserved vector)',
           '27 - default handler (intel reserved vector)',
           '28 - default handler (intel reserved vector)',
           '29 - default handler (intel reserved vector)',
           '30 - default handler (intel reserved vector)',
           '31 - default handler (intel reserved vector)',
           '32 - default handler',
           '33 - default handler',
           '34 - default handler',
           '35 - default handler',
           '36 - default handler',
           '37 - default handler',
           '38 - default handler',
           '39 - default handler',
           '40 - default handler',
           '41 - default handler',
           '42 - default handler',
           '43 - default handler',
           '44 - default handler',
           '45 - default handler',
           '46 - default handler',
           '47 - default handler',
           '48 - default handler',
           '49 - default handler',
           '50 - default handler',
           '51 - default handler',
           '52 - default handler',
           '53 - default handler',
           '54 - default handler',
           '55 - default handler',
           '56 - default handler',
           '57 - default handler',
           '58 - default handler',
           '59 - default handler',
           '60 - default handler',
           '61 - default handler',
           '62 - default handler',
           '63 - default handler',
           '64 - default handler',
           '65 - default handler',
           '66 - default handler',
           '67 - default handler',
           '68 - default handler',
           '69 - default handler',
           '70 - default handler',
           '71 - default handler',
           '72 - default handler',
           '73 - default handler',
           '74 - default handler',
           '75 - default handler',
           '76 - default handler',
           '77 - default handler',
           '78 - default handler',
           '79 - default handler',
           '80 - default handler',
           '81 - default handler',
           '82 - default handler',
           '83 - default handler',
           '84 - default handler',
           '85 - default handler',
           '86 - default handler',
           '87 - default handler',
           '88 - default handler',
           '89 - default handler',
           '90 - default handler',
           '91 - default handler',
           '92 - default handler',
           '93 - default handler',
           '94 - default handler',
           '95 - default handler',
           '96 - default handler',
           '97 - default handler',
           '98 - default handler',
           '99 - default handler',
           '100 - default handler',
           '101 - default handler',
           '102 - default handler',
           '103 - default handler',
           '104 - default handler',
           '105 - default handler',
           '106 - default handler',
           '107 - default handler',
           '108 - default handler',
           '109 - default handler',
           '110 - default handler',
           '111 - default handler',
           '112 - default handler',
           '113 - default handler',
           '114 - default handler',
           '115 - default handler',
           '116 - default handler',
           '117 - default handler',
           '118 - default handler',
           '119 - default handler',
           '120 - default handler',
           '121 - default handler',
           '122 - default handler',
           '123 - default handler',
           '124 - default handler',
           '125 - default handler',
           '126 - default handler',
           '127 - default handler',
           '128 - default handler',
           '129 - default handler',
           '130 - default handler',
           '131 - default handler',
           '132 - default handler',
           '133 - default handler',
           '134 - default handler',
           '135 - default handler',
           '136 - default handler',
           '137 - default handler',
           '138 - default handler',
           '139 - default handler',
           '140 - default handler',
           '141 - default handler',
           '142 - default handler',
           '143 - default handler',
           '144 - default handler',
           '145 - default handler',
           '146 - default handler',
           '147 - default handler',
           '148 - default handler',
           '149 - default handler',
           '150 - default handler',
           '151 - default handler',
           '152 - default handler',
           '153 - default handler',
           '154 - default handler',
           '155 - default handler',
           '156 - default handler',
           '157 - default handler',
           '158 - default handler',
           '159 - default handler',
           '160 - default handler',
           '161 - default handler',
           '162 - default handler',
           '163 - default handler',
           '164 - default handler',
           '165 - default handler',
           '166 - default handler',
           '167 - default handler',
           '168 - default handler',
           '169 - default handler',
           '170 - default handler',
           '171 - default handler',
           '172 - default handler',
           '173 - default handler',
           '174 - default handler',
           '175 - default handler',
           '176 - default handler',
           '177 - default handler',
           '178 - default handler',
           '179 - default handler',
           '180 - default handler',
           '181 - default handler',
           '182 - default handler',
           '183 - default handler',
           '184 - default handler',
           '185 - default handler',
           '186 - default handler',
           '187 - default handler',
           '188 - default handler',
           '189 - default handler',
           '190 - default handler',
           '191 - default handler',
           '192 - default handler',
           '193 - default handler',
           '194 - default handler',
           '195 - default handler',
           '196 - default handler',
           '197 - default handler',
           '198 - default handler',
           '199 - default handler',
           '200 - default handler',
           '201 - default handler',
           '202 - default handler',
           '203 - default handler',
           '204 - default handler',
           '205 - default handler',
           '206 - default handler',
           '207 - default handler',
           '208 - default handler',
           '209 - default handler',
           '210 - default handler',
           '211 - default handler',
           '212 - default handler',
           '213 - default handler',
           '214 - default handler',
           '215 - default handler',
           '216 - default handler',
           '217 - default handler',
           '218 - default handler',
           '219 - default handler',
           '220 - default handler',
           '221 - default handler',
           '222 - default handler',
           '223 - default handler',
           '224 - default handler',
           '225 - default handler',
           '226 - default handler',
           '227 - default handler',
           '228 - default handler',
           '229 - default handler',
           '230 - default handler',
           '231 - default handler',
           '232 - default handler',
           '233 - default handler',
           '234 - default handler',
           '235 - default handler',
           '236 - default handler',
           '237 - default handler',
           '238 - default handler',
           '239 - default handler',
           '240 - default handler',
           '241 - default handler',
           '242 - default handler',
           '243 - default handler',
           '244 - default handler',
           '245 - default handler',
           '246 - default handler',
           '247 - default handler',
           '248 - default handler',
           '249 - default handler',
           '250 - default handler',
           '251 - default handler',
           '252 - default handler',
           '253 - default handler',
           '254 - default handler',
           '255 - default handler'
       ]

dist_c = open('../src/default_handler.c', 'w')
dist_h = open('../src/default_handler.h', 'w')

sys.stdout = dist_c

for i, v in enumerate(info):
    print('''
        #include "default_handler.h"
        #include <stdint.h>
        #include "tools.h"
        #include "print.h"
        
        _Noreturn void int_{}_default_handler() {{
            uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
            char error_code_buf[17];
        
            __asm__ volatile (
            "mov rax, [rbp + 8]"
            : "=a"(error_code)
            );
        
            itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
            print("interrupt --- {}\\n");
            print("errorCode --- %\\n", error_code_buf);
        
            while (true) __asm__ volatile ("hlt");
        }}
    '''.format(i, v))

main = ',\n'.join([f'(void *)int_{i}_default_handler' for i in range(256)])
print(f'void *INT_DEFAULT_HANDLER_ARRAY[256] = {{{main}}};')

sys.stdout = dist_h

print('''
#ifndef __DEFAULT_HANDLER_ARRAY_H
#define __DEFAULT_HANDLER_ARRAY_H

extern void *INT_DEFAULT_HANDLER_ARRAY[256];

#endif
''')
