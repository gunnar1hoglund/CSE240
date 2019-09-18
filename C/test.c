#include <stdio.h>

// a pointer is a variable that holds a memory address
// direct addressing
// &a gets the address of the variable a
int main()
{
    int a = 6;

    int *b = &a;

    printf("%p\n", b);
}
