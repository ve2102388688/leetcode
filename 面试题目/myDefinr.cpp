#include <stab.h>

#define Conn(x,y) x##y
#define ToChar(x)  #@x
#define ToString(x) #x

int main(int argc, char *argv[])
{

    int a = Conn(12,34);
    char b = ToChar(1);
    char c[] = ToString(123);

    printf("%d, %s\n", a, c);

    return 0;
}