#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int m;

void
v(void) {
        char b[512];


        fgets(b, sizeof(b), stdin);
        printf(b);
        if(m == 64) {
                fprintf(stdout ,"Wait what?!\n");
                system("/bin/sh");
        }
}

int
main(int argc, char **argv) {
        v();
}