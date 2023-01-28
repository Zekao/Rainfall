# gdb writeup

```as
//Dump of assembler code for function main:
   0x0804851a <+0>:	push   %ebp
   0x0804851b <+1>:	mov    %esp,%ebp
   0x0804851d <+3>:	and    $0xfffffff0,%esp
   0x08048520 <+6>:	call   0x80484a4 <v>
   0x08048525 <+11>:	leave  
   0x08048526 <+12>:	ret    
//End of assembler dump.
(gdb) b v
    Breakpoint 1 at 0x80484ad
(gdb) r
Starting program: /home/user/level3/level3 
/Breakpoint 1, 0x080484ad in v ()
```
We will search if there is an address containing `/bin/sh` in our program

```as
    0x0804850c <+104>:	movl   $0x804860d,(%esp)
(gdb) x/s 0x804860d
    0x804860d:	 "/bin/sh"
```

Now, we will have to find the size of our buffer

With ghidra we can see that a variable `m` is present on the function v and his size is 64.

We can also see it with gdb 
```as
   0x080484df <+59>:	cmp    $0x40,%eax
//print 0x40
    64
```

After the 64th caracter, we will inject the /bin/sh address an a %n to produce a segfault right after it
