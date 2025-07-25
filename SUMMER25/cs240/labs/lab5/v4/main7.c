// Type casting: mixing of types in arithmetic operations.

#include <stdio.h>

int main() {
int x;
char y;

  x = 1;
  y = 'A';

  x = x + y;

  fprintf(stdout,"%d\n",x);

}
