#include "funcs40.h" /*header file with important things*/

void readvectors(int n, char * inputfile, int *u, int *v) {
  FILE *file = fopen(inputfile, "r"); // open file

  // for each column, it is added to u and v as vectors for matrix arithmatic later
  for(int i = 0; i < n; i ++) {
    fscanf(file, "%d %d", &u[i], &v[i]);
  }

  fclose(file); // always close file!
}
