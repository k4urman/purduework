#include <stdio.h>
#include "funcs11.h"

int main(){
  char inputstr[LENUP];
  int res = readinput(inputstr);

  if (res == ERRINPUT) {
    printf("Error");
    return 1;
  }

  printoutput(res, inputstr);
  return 0;
}
