// Command-line argument example:
// a version of cat command.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
FILE *fp;
int x;
char c;

  fp = fopen(argv[1],"r");
  if(fp == NULL) {
        fprintf(stderr,"file %s cannot be opened\n", argv[1]);
        exit(1);
  }

  while((x = fgetc(fp)) != EOF) {
	c = x;
	fprintf(stdout,"%c", c);
  }

}
