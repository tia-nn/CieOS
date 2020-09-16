import sys

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
