#include <stdio.h>

#define LENUP 12
#define ERRINPUT -1

int readinput(char *inputstr) {
  int count = 0; // cause \n is always apart of it
  char ch;

  while (count < LENUP - 1 && (ch = getchar()) != '\n' && ch != EOF) {
    inputstr[count++] = ch;
  }

  if (count == LENUP - 1 && ch != '\n' && ch != EOF) {
    printf("Error");
    return ERRINPUT;
  }

  inputstr[count] = '\0';
  return count+1;
}
