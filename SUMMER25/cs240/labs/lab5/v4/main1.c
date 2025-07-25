// Integer and real number representation: capacity limits.

#include <stdio.h>

int main() {

int x;
float y;

  x = 4000000001;
  y = 4000000421;

  fprintf(stdout,"%d\n",x);
  fprintf(stdout,"%f\n",y);

}
