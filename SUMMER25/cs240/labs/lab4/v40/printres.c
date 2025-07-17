#include "funcs40.h" /* header with important things */

void printres(int n, int **z) {

  // loops through z and prints every value in the matrix
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", z[i][j]);
    }
    printf("\n");
  }
}
