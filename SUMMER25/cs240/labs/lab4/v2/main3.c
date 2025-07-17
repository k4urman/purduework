// Variable length array (VLA) code that compiles.

#include <stdio.h>
#include <stdlib.h>

int main() {

FILE *fp;
int n;
int x[n];
int i;

  fp = fopen("test.dat","r");
  if(fp == NULL) {
	fprintf(stderr,"opening test.dat for read failed\n");
	exit(1);
  }

  fscanf(fp,"%d",&n);

  for(i=0; i<n; i++)
	fscanf(fp,"%d", &x[i]);

  for(i=0; i<n; i++)
	printf("%d\n", x[i]);

}
