
```bash
    run $(echo "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB")
    Program received signal SIGSEGV, Segmentation fault.
0x08048682 in main ()
```

```as
(gdb) info registers
eax            0x42424242       1111638594
ecx            0x4242   16962
edx            0x804c2b7        134529719
ebx            0x804a078        134520952
esp            0xbfffd460       0xbfffd460
ebp            0xbfffd488       0xbfffd488
esi            0x0      0
edi            0x0      0
eip            0x8048682        0x8048682 <main+142>
eflags         0x210283 [ CF SF IF RF ID ]
cs             0x73     115
ss             0x7b     123
ds             0x7b     123
es             0x7b     123
fs             0x0      0
gs             0x33     51
```

```as
x/x $esp
0xbfffd460:     0x0804a008
```

```as
x/50x 0x0804a008
0x804a008:      0x08048848      0x42424242      0x42424242      0x42424242
0x804a018:      0x42424242      0x42424242      0x42424242      0x42424242
0x804a028:      0x42424242      0x42424242      0x42424242      0x42424242
0x804a038:      0x42424242      0x42424242      0x42424242      0x42424242
0x804a048:      0x42424242      0x42424242      0x42424242      0x42424242
0x804a058:      0x42424242      0x42424242      0x42424242      0x42424242
0x804a068:      0x42424242      0x42424242      0x42424242      0x42424242
0x804a078:      0x42424242      0x42424242      0x42424242      0x42424242
0x804a088:      0x42424242      0x42424242      0x42424242      0x42424242
0x804a098:      0x42424242      0x42424242      0x42424242      0x42424242
0x804a0a8:      0x42424242      0x42424242      0x42424242      0x42424242
0x804a0b8:      0x42424242      0x42424242      0x42424242      0x42424242
0x804a0c8:      0x42424242      0x42424242
```