// v4/changeling1.c
#include <stdio.h>

void changeling1(int x)
{
  printf("addy x in changeling1: %p\n", (void*)&x);
  x = 100;
}
