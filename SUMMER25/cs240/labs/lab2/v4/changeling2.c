// v4/changeling2.c
#include <stdio.h>

void changeling2(int *y)
{
  printf("Address of y in changeling2: %p, Value at y: %d\n", (void*)y, *y);
  *y = 200;
}
