#include <iostream>
#include <cstring>
 
class N
{
public:
    N(int x) : number(x) {}
    void setAnnotation(char *a) {memcpy(annotation, a, strlen(a));}
    virtual int operator+(N &r) {return number + r.number;}
    virtual int operator-(N &r) {return number - r.number;}
private:
    char annotation[100];
    int number;
};
 
int main(int argc, char **argv)
{
    if(argc < 2) _exit(1);
 
    N *x = new N(5);
    N *y = new N(6);
    N &five = *x, &six = *y;
 
    five.setAnnotation(argv[1]);
 
    return six + five;
}