#include "funcs40.h" /* header file with importnat things */

void outprodcalc(int n, int *u, int *v, int **z) {

  /*z is a 2D array used as a matrix. Outerproduct means
   * to multiple each of the members of u by v and storing it
   * in a N x N matrix.*/
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      z[i][j] = u[i] * v[j];
    }
  }
}
