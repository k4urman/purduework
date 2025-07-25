#include "funcs16.h" 


void buildstruct(char *filename, int linemax, struct linesstruct *filedat) {
  //open file
  FILE *fp = fopen(filename, "r");

  //make sure it is not NULL otherwise error
  if (fp == NULL) {
    fprintf(stderr,"Error: cannot open file for reading\n");
    exit(1);
  }
  
  // make sure to allocate memory for the buffer
  char *buff = malloc(linemax + 1);

  // make sure buffer is not NULL, otherwise allocation failed.
  if (buff == NULL) {
    printf("Error: failed allocate memory 4 linebuff\n");
    fclose(fp);
    exit(1);
  }

  //important varaibles
  int c;
  int cline = 0;
  int charindex = 0;

  /*loop through fp for each c until it reaches EOF
   * each buffer index should store the c and then increment the index
   * if c is a newline, we null terminate the buffer to end the string
   * we change the struct for the current line index to allocate memeory for 
   * however many indexes there were.
   * make sure the struct .datatypes properly ahd memeory allocated.
   * free after use
   *
   * copy the databytes for the index in the struct to the buffer.
   * increment current line and restart char index*/
  while ((c = fgetc(fp)) != EOF) {
    buff[charindex] = c;
    charindex++;

    if (c == '\n') {
      buff[charindex] = '\0';

      filedat[cline].databytes = malloc(charindex);
      if (filedat[cline].databytes == NULL) {
        printf("Error: failed allocation 4 linedata\n");
        free(buff);
        fclose(fp);
        exit(1);
      }

      strcpy(filedat[cline].databytes, buff);

      filedat[cline].id = cline;
      filedat[cline].len = charindex;
      filedat[cline].next = NULL;

      cline++;
      charindex = 0;
    }
  }

  // free buffer to allow memeory allocation later
  // and close file

  free(buff);
  fclose(fp);
}
