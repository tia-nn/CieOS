code = open('hankaku.txt').read()

fonts = code.split('\n\n')

print('#ifndef __HANKAKU_FONT_C')
print('#define __HANKAKU_FONT_C')

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

print('#endif')
