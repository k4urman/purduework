// Pointers, memory, and silent run-time errors.

#include <stdio.h>

int s[5];

int main()
{
    int i;

    for(i = 0; i < 5; i++)
        s[i] = i;

    for(i = 0; i < 5; i++)
        printf("%d\n", s[i]);

    for(i = 0; i < 500; i++)
        s[i] = i;
    for(i = 0; i < 500; i++)
        printf("%d\n", s[i]);
    return 0;
}
