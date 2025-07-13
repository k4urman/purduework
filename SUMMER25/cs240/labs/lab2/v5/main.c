// Another passing by address/reference example.

#include <stdio.h>

void changeval(int *);

int main()
{
int s;

  s = 3;

  printf("inside main():\n");
  printf("value of s = %d\n", s);
  printf("address of s = %p\n", &s);
  printf("\n");

  // jump to changeval()
  changeval(&s);

  printf("back to main():\n");
  printf("value of s = %d\n", s);
  printf("address of s = %p\n", &s);

}


void changeval(int *t)
{
  printf("inside changeval():\n");

  // where does argument t live?
  printf("address of argument t %p\n", &t);

  // what is the value of argument t?
  printf("value of argument t %p\n", t);
  printf("\n");

  *t = 99;
}
