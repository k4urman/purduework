// Type casting: demotion.

#include <stdio.h>

int main() {
float x;
double y;

  y = -21.1234567893;
  x = y;

  fprintf(stdout,"%.9lf %.9f\n", y, x);

}
