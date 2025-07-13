// Use functions changeling1() and changeling2() to illustrate
// passing by value vs. reference (i.e., address).

#include <stdio.h>

void changeling1(int);
void changeling2(int *);

int main()
{
    int r;

    r = 7;

    printf("addy r in main: %p\n", (void*)&r);
    changeling1(r);
    printf("%d\n", r);

    r = 9;
    changeling2(&r);
    printf("%d\n", r);

    return 0;
}

void changeling1(int x)
{
    printf("addy x in changeling1: %p\n", (void*)&x);
    x = 100;
}

void changeling2(int *y)
{
    printf("addy y in changeling2: %p, val y: %d\n", (void*)y, *y);
    *y = 200;
}
