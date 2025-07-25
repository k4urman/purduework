// Type casting: promotion across different types.
// Auxiliary issue: fgetc().

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
FILE *fp;
int i, z;
char c;

  // open file to read
  if((fp = fopen(argv[1],"r")) == NULL) {
        fprintf(stderr,"open file %s failed\n", argv[1]);
        exit(1);
  }

  i = 0;
  while((z = fgetc(fp)) != EOF) {
	c = z;
	printf("i = %d  z = %d  c = %c\n", i++, z, c);
  }

}
