// Command-line argument example:
// a basic version of wc command to 
// determine size (in bytes) of a file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
FILE *fp;
int count = 0;
int countlines = 0;
int option;
int x;

  // open file
  fp = fopen(argv[1],"r");
  if(fp == NULL) {
        fprintf(stderr,"file %s cannot be opened\n", argv[1]);
        exit(1);
  }

  if(argv[2] == NULL)
	option = 0;
  else if(strcmp(argv[2], "-c") == 0)
	option = 0;
  else if(strcmp(argv[2], "-l") == 0)
	option = 1;
  else {
	fprintf(stdout, "Invalid option.\n");
	exit(1);
  }

  while((x = fgetc(fp)) != EOF) {
	if(option == 0)
		count++;
	else if(x == '\n')
		countlines++;
  }

  if(option == 0)
	printf("size of %s: %d (bytes)\n", argv[1], count);
  else
	printf("number of lines in %s: %d\n", argv[1], countlines);

}
