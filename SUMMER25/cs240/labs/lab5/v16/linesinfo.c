#include "funcs16.h"

//takes in a filename, the number of lines in said file and max
void linesinfo(char *filename, unsigned int *numlines, unsigned int *linemax) {
  //open said filename given
  FILE *fp = fopen(filename, "r");

  // make sure it is not null, otherwise, error
  if (fp == NULL) {
    fprintf(stderr, "Error: cannot open file\n");
    exit(1);
  }

  // important variables
  int c;
  unsigned int lines = 0;
  unsigned int clinelength = 0;
  unsigned int maxlength = 0;
  int lcharnewline = 0;
  int filestuff = 0;

  /*
   * Loop by getting each char in fp until you hit EOF
   * filestuff just amkes sure there is stuff inside the file
   * count how many lines there are while clinelength is currrent
   * reset current line length after each new line we are on and keep counting
   * make sure all are not Non-ASCII, otherwise error
   */
  while ((c = fgetc(fp)) != EOF) {
    filestuff = 1;

    if (c == '\n') {
      lines++;
      if (clinelength > maxlength) {
        maxlength = clinelength;
      }
      clinelength = 0;
      lcharnewline = 1;
    } else {

      if (c < 0 || c > 127) {
        fprintf(stderr,"Error: file has non-ASCII char\n");
        fclose(fp);
        exit(1);
      }

      clinelength++;
      lcharnewline = 0;
    }
  }

  // if nothing inside file, we return a error
  if (!filestuff) {
    fprintf(stderr,"Error: file empty\n");
    fclose(fp);
    exit(1);
  }

  // last char newline needs to exist and if it does not, give error
  if (!lcharnewline) {
    fprintf(stderr,"Error: file has no newline at end\n");
    fclose(fp);
    exit(1);
  }

  // only 1 line exception
  if (lines == 0 && filestuff) {
    lines = 1;
  }

  //close file to avoid any issues
  fclose(fp);

  // change the numlines and linemax in main to be used
  *numlines = lines;
  *linemax = maxlength;
}
