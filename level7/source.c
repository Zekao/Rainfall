#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char c[80];

struct internet {
        int priority;
        char *name;
};

void m(void) {
        printf("%s - %d\n", c, time(NULL));
}

int main(int argc, char **argv) {

        struct internet *i1, *i2, *i3;

        i1 = malloc(sizeof(struct internet));
        i1->priority = 1;
        i1->name = malloc(8);

        i2 = malloc(sizeof(struct internet));
        i2->priority = 2;
        i2->name = malloc(8);

        strcpy(i1->name, argv[1]);
        strcpy(i2->name, argv[2]);
        fgets(c, 68, fopen("/home/user/level8/.pass", "r"));

        printf("~~\n");
        return (0);
}