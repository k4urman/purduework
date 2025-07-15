// Basic file I/O.

#include <stdio.h>
#include <stdlib.h>

int main() {

FILE *f1, *f2;
int i, j, val[50];
char name[100];

  // read filename from stdin
  scanf("%s", name);

  // open file to read
  if((f1 = fopen(name,"r")) == NULL) {
	fprintf(stderr,"file %s does not exist\n", name);
	exit(1);
  }

  // open file to write
  f2 = fopen("result.dat","w");
  if(f2 == NULL) {
	fprintf(stderr,"creating file result.dat failed\n");
	exit(1);
  }

  // read data
  i = 0;
  while(fscanf(f1,"%d", &val[i]) != EOF)
	i++;

  // write doubled data
  for(j=0; j<i; j++)
  	fprintf(f2,"%d\n", 2 * val[j]);

  fclose(f1);
  fclose(f2);

}
