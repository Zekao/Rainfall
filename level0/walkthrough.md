### LEVEL 00

In this exercice, we have an executable file called `level0` that segfaults when executed without arguments.

```bash
$ ls -l
-rwsr-x---+ 1 level1 users 747441 Mar  6  2016 level0
```

If you add an argument to it, it won't segfault and it will print something to the standard output.

```bash
$ ./level0
Segmentation fault (core dumped)
```

```bash
$ ./level0 akajdhajsd
No !
```

When you dissasemble the binary, you will see that it does an atoi in our first argument and it
compares it to an hexadecimal value which is 0x1a7 and it correspond to 423
```c
iVar1 = atoi(*(char **)(param_2 + 4))
  if (iVar1 == 0x1a7) {
   ........
  }
```

```bash
    cat /home/user/level1/.pass
```
