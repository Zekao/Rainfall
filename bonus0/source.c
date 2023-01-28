#include <stdio.h>
#include <string.h>
 
void
p(char *name, char *msg){
  char buf[4096];
 
  puts(msg);
  read(0, buf, sizeof buf);
  *strchr(buf, '\n') = 0;
  strncpy(name, buf, 20);
}
 
void 
pp(char *fullname) {
  char last[20];
  char first[20];
 
  p(first, " - ");
  p(last, " - ");
 
  strcpy(fullname, first);
  strcat(fullname, " ");
  strcat(fullname, last);
}
 
int
main(int argc, char **argv){
  char fullname[42];
 
  pp(fullname);
  printf("%s\n", fullname);
  return 0;
}