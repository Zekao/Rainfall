#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

# define FILE_PASS "/home/user/end/.pass"

int main(int argc, char **argv){
        FILE *fp = fopen(FILE_PASS, "r");
        struct {char pass[66], msg_err[66]} pwfile = {{0}};
        char ptr[0];

        if(!fp || argc != 2)
                return -1;

        fread(pwfile.pass, 1, 66, fp);
        pwfile.pass[65] = 0;
        ptr[atoi(argv[1])] = 0;
        fread(pwfile.msg_err, 1, 65, fp);
        fclose(fp);

        if(!strcmp(pwfile.pass, argv[1]))
                execl("/bin/sh", "sh", 0);
        else
                puts(pwfile.msg_err);

        return 0;
}