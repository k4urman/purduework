// Use functions changeling1() and changeling2() to illustrate
// passing by value vs. reference (i.e., address).

// mainv2.c
#include <stdio.h>

void changeling1(int);
void changeling2(int *);

int main()
{
  int r;

  r = 7;
  printf("Address of r in main: %p\n", (void*)&r);
  changeling1(r);
  printf("%d\n", r);

  r = 9;
  changeling2(&r);
  printf("%d\n", r);

  return 0;
}
