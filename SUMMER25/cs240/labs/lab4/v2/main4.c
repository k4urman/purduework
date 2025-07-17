// Variable length array (VLA) example that will compile and run.
// Please do not use VLAs as they are not part of the core C standard.

#include <stdio.h>
#include <stdlib.h>

int main() {

int n;
int x[n];
int i;

  scanf("%d",&n);

  for(i=0; i<n; i++)
	x[i] = i;

  for(i=0; i<n; i++)
	printf("%d\n", x[i]);
}
