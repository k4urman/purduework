// Program to inspect the 32 bits of int.
// Output: reverse order v2.

#include <stdio.h>

int main()
{
int x, z;
unsigned int m, y;
int i;

  // read input unsigned
  scanf("%d", &x);

  // set mask to 0x01
  // m = ~(~0 << 1);
  m = 1;

  // loop over all 32 bits from msb to lsb
  for(i=0; i<32; i++) {
	// right shift to inspect the more significant bits first
	z = x >> 31-i;
	// zero out all bits but for lsb
	y = z & m;
  	printf("%d", y);
  }

  printf("\n");
}
