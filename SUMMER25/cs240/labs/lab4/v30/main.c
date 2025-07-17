/*Header file with important things*/
#include "funcs30.h"

int main() {
  /*files to read in and out of*/
  FILE *in;
  FILE *out;

  /*used for input proc holding and counting from bit position*/
  unsigned short bp;
  int ccount;

  printf("Please give a filename to unscramble or scramble: ");

  /*Whatever the count was of the filename*/
  ccount = inputproc(&in, &out);

  /*finds the bit position*/
  bp = ccount % 8;

  /*performs the bit sliding position*/
  fileproc(in, out, bp);

  /*closes the file after use to avoid any errors later on*/
  fclose(in);
  fclose(out);

  printf("Done.\n");
  return 0;
}
