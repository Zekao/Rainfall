#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char 
*p(void) {
        char            buffer[64];
        unsigned int    ret;

        printf(""); fflush(stdout);
        gets(buffer);
        ret = __builtin_return_address(0);
        if((ret & 0xb0000000) == 0xb0000000) {
                printf("(%p)\n", ret);
                _exit(1);
        }
        printf("%s\n", buffer);
        return strdup(buffer);
}

int
main(int argc, char **argv) {
        p();
}