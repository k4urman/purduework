// struct and bit fields.

#include <stdio.h>

struct bitflags {
  unsigned int b0 : 1;
  unsigned int b1 : 1;
  unsigned int b2 : 1;
  unsigned int b3 : 1;
};

int main()
{
struct bitflags x;

  x.b0 = 1;
  x.b1 = 0;
  x.b2 = 0;
  x.b3 = 1;

  printf("%lu\n",sizeof(x));
  printf("%d\n",x.b0);
  printf("%d\n",x.b1);
  printf("%d\n",x.b2);
  printf("%d\n",x.b3);

}
