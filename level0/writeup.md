# Level 0

### In this level, we have an executable called level0, it have been created by user level1
```bash
level0@RainFall:~$ ls -l
total 732
-rwsr-x---+ 1 level1 users 747441 Mar  6  2016 level0
```
If we launch it without parameter, it segfault
```bash
level0@RainFall:~$ ./level0 
Segmentation fault (core dumped)
```
If we give it an argument, it tells "No!"
```bash
level0@RainFall:~$ ./level0 test
No !
level0@RainFall:~$
```
It means that we have to find a specific parameter, for that, we will use gdb (see the [gdb writeup](gdbwriteup.md))

After investing, we found that the value that we have to enter is 423

```bash
level0@RainFall:~$ ./level0 423
$ whoami
level1
$ cat /home/user/level1/.pass
1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a
```