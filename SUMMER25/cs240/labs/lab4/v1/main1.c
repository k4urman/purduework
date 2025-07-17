// Program to inspect the 32 bits of int.

#include <stdio.h>

int main()
{
int x;
unsigned int m, y;
int i;

  // read int input
  scanf("%d", &x);

  // set mask to 0x00000001
  m = ~(~0 << 1);

  // loop over all 32 bits from lsb to msb
  for(i=0; i<32; i++) {
	// zero out all bits but for lsb
	y = x & m;
  	printf("%u", y);
	// right shift to inspect the next significant bit
	x = x >> 1;
  }

  printf("\n");
}
