// Local vs. global variables:
// scope and conflicting names.

#include <stdio.h>

void fun9(void);

int x = 100;

int main()
{
int x = 200;

  printf("main: x = %d\n", x);

  fun9();

}
