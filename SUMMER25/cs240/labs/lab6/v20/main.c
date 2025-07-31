#include <stdio.h> //header file for all c files

//function prototype for myconcat. Extern since it is
//within the directory of main.c and c will find the other file
extern char *myconcat(int n, ...);

int main() {
  // ati prints properly
  printf("a + t + i= %s\n", myconcat(3, "a", "t", "i"));

  // cat prints properly
  printf("c + a + t = %s\n", myconcat(4, "c", "a", "t", "\0"));

  //returns null because there are less arguments given then told
  printf("c + a + t = %s\n", myconcat(4, "c", "a", "\0"));

  // cat8 prints properly
  printf("c + a + t + 8 = %s\n", myconcat(4, "c", "a", "t", "8", "7uiuhiub" "kjnkj));
}
