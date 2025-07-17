// Program to inspect the 32 bits of int.
// Output: reverse order v1.

#include <stdio.h>

int main()
{
int x;
unsigned int m, y;
int i;
int z[32];

  // read input unsigned
  scanf("%d", &x);

  // set mask to 0x00000001
  m = ~(~0 << 1);

  // loop over all 32 bits from lsb to msb
  for(i=0; i<32; i++) {
	// zero out all bits but for lsb
	y = x & m;
	// save bit values in array
	z[i] = y;
  	// printf("%d", y);
	// right shift to inspect the next significant bit
	x = x >> 1;
  }

  // output bit values in reverse order: msb first, lsb last
  for(i=31; i>=0; i--) {
  	printf("%d", z[i]);
  }

  printf("\n");
}
