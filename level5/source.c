#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int m;

void
o(void) {
        system("/bin/sh");
        _exit(1);
}

void
n(void){
        char b[512];

        fgets(b, sizeof(b), stdin);
        printf(b);
        exit(1);   
}

int 
main(int argc, char **argv) {
        n();
}