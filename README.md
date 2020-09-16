Cで書く自作OS x86_64 uefi

ブートローダは[これ](https://github.com/Lan-t/MyOsLoader)

CMakeLists.txtの最後の2行は自分の環境用

## pre-build

``` shell script
cd scripts
python make.c.py
```
