# GDB Writeup

```bash
(gdb) disass main
Dump of assembler code for function main:
   0x08048ec0 <+0>:     push   %ebp
   0x08048ec1 <+1>:     mov    %esp,%ebp
   0x08048ec3 <+3>:     and    $0xfffffff0,%esp
   0x08048ec6 <+6>:     sub    $0x20,%esp
   0x08048ec9 <+9>:     mov    0xc(%ebp),%eax
   0x08048ecc <+12>:    add    $0x4,%eax
   0x08048ecf <+15>:    mov    (%eax),%eax
   0x08048ed1 <+17>:    mov    %eax,(%esp)
   0x08048ed4 <+20>:    call   0x8049710 <atoi>
   0x08048ed9 <+25>:    cmp    $0x1a7,%eax
```

We can see that there is a comparaison between 0x1a7 and %eax
>You can read [this](https://web.archive.org/web/20191114093028/https://gerardnico.com/computer/cpu/register/general) to understand what is eax and other registers

```bash
(gdb) print 0x1a7
$1 = 423
```
The value that the program is waiting is 423