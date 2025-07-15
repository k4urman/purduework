/* 2-D arrays viewed as pointers to pointers: */
/* double indirection. */

#include <stdio.h>

int main()
{
int i, j;
int x[2][3];

// initialize 2-D array

  for (i=0; i<2; i++)
	for (j=0; j<3; j++)
	  x[i][j] = 10 * i + j;

// print 2-D array
  for (i=0; i<2; i++)
	for (j=0; j<3; j++)
	  if (j != 2)
		printf("x[%d][%d] = %d  ", i, j, x[i][j]);
	  else
	  	printf("x[%d][%d] = %d\n", i, j, x[i][j]);

  printf("%d\n", **x);
  printf("%d\n", *((*x)+2));
  printf("%d\n", *(*x+1));	// note precedence rule
  printf("%d\n", **(x+1));
  printf("%d\n", *(*(x+1)+2));

}
