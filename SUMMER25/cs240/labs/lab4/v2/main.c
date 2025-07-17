// Dynamic memory allocation in processes using malloc().

#include <stdio.h>
#include <stdlib.h>

int main() {

int x;
int *y;

  printf("&x = %p \t y = %p\n", &x, y);

  x = 1000;
  //*y = 2000;

  // Request that Linux allocate 4 bytes in main memory and
  // return beginning address.
  y = (int *) malloc(sizeof(int));
  *y = 2000;

  printf("&x = %p \t y = %p\n", &x, y);
  printf("%d %d\n", x, *y);

  printf("main = %p\n", main);

}
