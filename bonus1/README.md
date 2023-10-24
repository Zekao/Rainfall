# bonus 1

## Vulnerable Code

The memcpy function copies data into the buf array based on a size derived from user input without validating this size, leading to a potential buffer overflow.

## Exploit Overview

1. Input a negative integer -2147483637 which bypasses the program's initial boundary check due to integer overflow but results in count \* sizeof(int) being 44.
2. Provide a string of 44 characters: 40 arbitrary characters followed by the string "FLOW".
3. The 40 characters fill the buf, and the "FLOW" overflows into the count variable.
4. The program checks if count matches the magic value 0x574f4c46 (reverse of "FLOW") and, if it does, spawns a shell.

## Running the Exploit

Execute the vulnerable program with the crafted payload:

```bash
./bonus1 -2147483637 $(python -c 'print "A" * 40 + "FLOW"')
```

This should spawn a shell.
