#include "funcs40.h" /*header file with important things*/

int findsize (char *inputfile) {
  //opens file or returns -1 to make main give error message
  FILE *file = fopen(inputfile, "r");
  if (file == NULL) {
    return -1;
  }

  // integers to find N
  int count = 0;
  int val1, val2;
  char check;
  int valid = 1;

  // loops through and gives valid N
  while(1) {
    if(fscanf(file, "%d %d", &val1, &val2) != 2) {
      if (count > 0) {
        break;
      } else {
        valid = 0;
	break;
      }
    }

    count++;
    check = fgetc(file);
    if(check == '\n') {
      continue;
    } else if(check == EOF) {
      break;
    } else{
      valid = 0;
      break;
    }
  }

  // make sure to close file
  fclose(file);

  // if the last line does not indent and there is a count, we return N
  if((valid && count) > 0) {
    return count;
  } else {
    return -1;
  }
}
