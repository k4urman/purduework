#include "funcs40.h" /*header file with all important things*/

int main() {
  char filename[12]; //filename to store max 12 char
  int i, input_too_long = 0; // i used for loo and i_t_l as a bool check
  int ch; // check each char in filename

  printf("enter filename (max 11 char): ");

  while (i < 12 && (ch = getchar()) != EOF && ch != '\n') {
    filename[i++] = (char)ch;
  }

  // check if longer than 12
  if (i == 12 && (ch != '\n' && ch != EOF)) {
    input_too_long = 1;

    while ((ch = getchar()) != '\n' && ch != EOF);
  }

  filename[i] = '\0';  // null terminante the last one

  // if file longer than 12
  if (input_too_long) {
    fprintf(stderr, "Error: filename longer than max char.\n");
    exit(1);
  }

  // if enter is empty
  if (i == 0) {
    fprintf(stderr, "Error: no filename given.\n");
    exit(1);
  }

  // findsize is called and error is given if there is a problem.
  int N = findsize(filename);
  if (N == -1) {
    printf("Error: cannot open file.\n");
    exit(1);
  }

  // u allocation, or error
  int *u = (int *)malloc(N * sizeof(int));
  if (u == NULL) {
    printf("cannot allocate memory for u\n");
    exit(1); // Indicate an error
  }

  // v allocation, or error
  int *v = (int *)malloc(N * sizeof(int));
  if (v == NULL) {
    printf("cannot allocate memory for v\n");
    exit(1); // Indicate an error
  }

  // z allocation, or error
  int **z = (int **)malloc(N * sizeof(int *));
  if (z == NULL) {
    printf("cannot allocate memory for u\n");
    exit(1); // Indicate an error
  }

  // z[i] allocation
  for(int i = 0; i < N; i++) {
    z[i] = (int *)malloc(N * sizeof(int));
  }

  // all the other functions are called and ran
  // read vectors makes vectors in u and v
  readvectors(N, filename, u, v);

  // outprodcalc does the matrix math
  outprodcalc(N, u, v, z);

  //print the result
  printres(N, z);

  //frees all the pointers we used to be reused later
  free(u);
  free(v);
  for(int i = 0; i < N; i++) {
    free(z[i]);
  }
  free(z);

  return 0;
}
