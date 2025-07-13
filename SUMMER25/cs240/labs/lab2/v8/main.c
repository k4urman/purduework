// Pointers and arrays: valid vs. invalid memory.

#include <stdio.h>

int main()
{
int *z;

  *z = 100;
  *(z+1) = 200;
  *(z+2) = 300;

  printf("%d\n",*z);
  printf("%d\n",*(z+1));
  printf("%d\n",*(z+2));

}
