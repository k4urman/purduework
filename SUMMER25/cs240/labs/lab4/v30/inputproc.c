#include "funcs30.h"

int inputproc(FILE **infile, FILE **outfile) {
  /*
   * filename to be stored
   * i for each character reading to be placed into filename
   * ccount is the character count/index of filename we are on
   */

  char filename[MAX];
  int i;
  int ccount = 0;


  /*
   * Loops through each character given and makes sure
   * that it is a alphabetical character and it it not a space
   * otherwise a error is given. Also makes sure it is not above
   * the MAX requirement in header file
   */

  while ((i = getchar()) != '\n') {
    if ((i >= 65) && (i <= 95) && (i == ' ')) {
      fprintf(stderr, "Error: input has invalid char \n");
      exit(1);
    }
    if (ccount > MAX) {
      fprintf(stderr, "Error: too many char in filename\n");
      exit(1);
    }
    filename[ccount] = i;
    ccount++;
  }

  /*All strings much \0 at the end for computer to know*/
  filename[ccount] = '\0';

  /*
   * No response is alos handled and returns an error.
   * We talk about this in the pdf for this lab.
   */

  if (ccount == 0) {
    printf("Error: no input \n");
    exit(1);
  }

  /*input file is opened and read into the pointer or given an error*/
  *infile = fopen(filename, "r");
  if (*infile == NULL) {
    printf("Error: reading file unable to be opened\n");
    exit(1);
  }

  /*
   * Now it checks if it is a scrambled file with _y or if
   * it needs to be scrambled. It checks the last two characters
   * and ccount is at the very last index as of that moment. If
   * scrambled the outputfile is created without _y otherwise is.
   */

  if (filename[ccount - 2] == '_' && filename[ccount - 1] == 'y') {
    filename[ccount - 2] = '\0';
    ccount = ccount - 2;
  } else {
    filename[ccount] = '_';
    filename[ccount + 1] = 'y';
    filename[ccount + 2] = '\0';
  }

  /*reads in the output filename we gave*/
  *outfile = fopen(filename, "w");
  if (*outfile == NULL) {
    printf("Error: writing file unable to be opened \n");
    exit(1);
  }

  /*returns the length of the filename*/
  return ccount + 1;
}
