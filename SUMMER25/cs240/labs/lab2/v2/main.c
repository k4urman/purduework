// Meaning of a pointer: a variable whose content is an address.

#include <stdio.h>

int main()
{
int x, *y, **r, ***s, ****t;

  x = 7;
  printf("%d\n", x);
  printf("%p\n", &x);

  y = &x;
  printf("%d\n", *y);
  printf("%p\n", y);

  r = &y;
  printf("%d\n", **r);
  printf("%p\n", r);

  /*
  r = &&x;
  printf("%d\n", **r);
  printf("%p\n", r);
  */

  s = &r;
  printf("%d\n", ***s);
  printf("%p\n", s);

  t = &s;
  printf("%d\n", ****t);
  printf("%p\n", t);

  // meaning of int **z?
}
