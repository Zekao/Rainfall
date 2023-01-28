#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

#define FILE_PASS "/bin/cat /home/user/level7/.pass"

struct data {
        char name[64];
};

struct fp {
        int (*fp)();
};

void n (void) {
        system(FILE_PASS);
}

void m(void) {
        printf("Nope\n");
}

int main(int argc, char **argv) {
        struct data *d;
        struct fp *f;

        d = malloc(sizeof(struct data));
        f = malloc(sizeof(struct fp));
        f->fp = m;
        strcpy(d->name, argv[1]);
        f->fp();
}