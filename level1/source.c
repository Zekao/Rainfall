#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void
run(void) {
        fprintf(stdout, "Good... Wait what?\n");
        system("/bin/sh");
}

        int
main(int argc, char **argv)
{
        char buffer[64];

        gets(buffer);
}