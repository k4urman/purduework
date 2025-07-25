#include <stdio.h>
#include "funcs11.h"

int readinput(char *inputstr) {
  int count = 0; // add the \0 null term
  char ch;

  while (count < LENUP - 1 && (ch = getchar()) != '\n' && ch != EOF) {
    inputstr[count++] = ch;
  }

  if (count == LENUP - 1 && ch != '\n' && ch != EOF) {
    printf("Error");
    return ERRINPUT;
  }

  inputstr[count] = '\0';
  return count + 1;
}
