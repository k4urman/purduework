// Basic file I/O.

#include <stdio.h>
#include <stdlib.h>

int main() {

FILE *fp;
int a;
float b;
char c[10];

  // open file to read
  fp = fopen("data.txt","r");

  // open failed
  if(fp == NULL) {
	fprintf(stderr,"file data.txt does not exist\n");
	exit(1);
  }

  fscanf(fp,"%d %f %s", &a, &b, c);
  fprintf(stdout,"%d %f %s\n", a, b, c);

}
