#include <string.h>
#include <unistd.h>
#include <stdio.h>

int
main(int argc, char **argv){
        gid_t           gid;
        uid_t           uid;
        char            *array[2];


        if (atoi(argv[1]) == 423){
                array[0] = strdup("/bin/sh");
                array[1] = NULL;
                gid = getegid();
                uid = geteuid();
                setresgid(gid, gid, gid);
                setresuid(uid, uid, uid);
                execv("/bin/sh", array);
        }
        else
                fprintf(stderr, "No !\n");
        return (0);
}