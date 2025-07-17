// malloc() example involving 2-D tables containing integers.

#include <stdio.h>
#include <stdlib.h>

int main() {

int i, j;
FILE *fp;
int row, col;
int **table2d;

  fp = fopen("test2d.dat","r");
  if(fp == NULL) {
	fprintf(stderr,"opening test2d.dat for read failed\n");
	exit(1);
  }

  // read the size of 2-D table
  // robust input?
  fscanf(fp, "%d %d", &row, &col);

  // allocate space for pointers for rows
  table2d = (int **) malloc(row * sizeof(int *));
  if(table2d == NULL) {
	fprintf(stderr,"malloc failed\n");
	exit(1);
  }

  // for each row, allocate space for columns
  for(i=0; i<row; i++)
	*(table2d + i) = (int *) malloc(col * sizeof(int));

  // read 2D integer table values
  for(i=0; i<row; i++)
  	for(j=0; j<col; j++)
	  fscanf(fp, "%d", &table2d[i][j]);

  // print to stdout
  for(i=0; i<row; i++) {
  	for(j=0; j<col; j++)
	  printf("%d ", table2d[i][j]);
	printf("\n");
  }

}
