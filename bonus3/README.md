# bonus 3

In this level, we have an executable which is taking an argument

while checking the source code, we can see that it will do a comparaison between a variable and argv[1] and if it's the same value, it will spawn a shell

We can just simply do a 

```bash
bonus3@RainFall:~$ ./bonus3 ""
$ whoami
end
```

and a `/bin/sh` spawned....