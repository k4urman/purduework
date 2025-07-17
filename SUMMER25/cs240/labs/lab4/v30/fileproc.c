#include "funcs30.h" //header file

void fileproc(FILE *infile, FILE *outfile, unsigned short ib) {
  /*current bit position to flip*/
  int x;
  unsigned short y = ib;

  /*
   * reads input byte by byte and creates a mask for the yth
   * place and flips it using ^=
   * Then it will print it into the outputfile we created earlier
   * before moving onto the next until string it done
   */

  while ((x = fgetc(infile)) != EOF) {
    unsigned short z = ~(~0 << y);

    x ^= z;

    fprintf(outfile, "%c", x);
    y = (y + 1) % 8;
  }
}
