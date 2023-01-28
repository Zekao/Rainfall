#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define FILE_PASS "/bin/cat /home/user/level5/.pass"

int m;

void
p(char *string) {
        printf(string);
}

void
n(void) {
        char            b[512];

        fgets(b, sizeof(b), stdin);
        p(b);
        if(m == 0x01025544) {
                system(FILE_PASS);
        }
}

int
main(int argc, char **argv) {
        n();
}