// Local vs. global variables:
// referencing globals from different files.

#include <stdio.h>

extern int x;

void fun9(void)
{

  printf("fun9: x = %d\n", x);

}
