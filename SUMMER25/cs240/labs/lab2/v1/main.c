// Program to illustrate content vs. address
// of a local variable.

#include <stdio.h>

int main()
{
int x;

  printf("%d\n",x);

  // format %p is for printing address
  printf("%p\n",&x);

}
