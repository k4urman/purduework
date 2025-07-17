// More useful malloc() example.

#include <stdio.h>
#include <stdlib.h>

int main() {

FILE *fp;
int n, *x;
int i;

  fp = fopen("test.dat","r");
  if(fp == NULL) {
	fprintf(stderr,"opening test.dat for read failed\n");
	exit(1);
  }

  fscanf(fp,"%d",&n);

  x = (int *) malloc(n * sizeof(int));
  if(x == NULL) {
	fprintf(stderr,"malloc failed\n");
	exit(1);
  }

  for(i=0; i<n; i++)
	fscanf(fp,"%d", &x[i]);

  for(i=0; i<n; i++)
	fprintf(stdout,"%d\n", x[i]);

  free(x);

}
