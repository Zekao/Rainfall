#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{
        EN,
        FN,
        NL,
};

int language = EN;

struct UserRecord{
        char name[40];
        char password[32];
        int id;
};

void
greetuser(struct UserRecord user){
        char greeting[64];
        switch(language){
                case EN:
                        strcpy(greeting, "Hello "); break;
                case FN:
                        strcpy(greeting, "Hyvää päivää "); break;
                case NL:
                        strcpy(greeting, "Goedemiddag! "); break;
        }
        strcat(greeting, user.name);
        printf("%s\n", greeting);
}

int
main(int argc, char **argv, char **env){
        if(argc != 3) {
                return 1;
        }
        struct UserRecord user = {0};
        strncpy(user.name, argv[1], sizeof(user.name));
        strncpy(user.password, argv[2], sizeof(user.password));

        char *envlang = getenv("LANG");
        if(envlang)
                if(!memcmp(envlang, "fi", 2))
                        language = FN;
                else if(!memcmp(envlang, "nl", 2))
                        language = NL;
        greetuser(user);
}