// Example: using, char *, type casting to access
// components of struct.

#include <stdio.h>
#include <stdlib.h>

struct abc {
  int x1;
  float y1;
  int x2;
  int x3;
  float y2;
};

int main() 
{
struct abc s;
char *m;

  s.x1 = 64;
  s.y1 = 0.1;
  s.x2 = 64;
  s.x3 = 64;
  s.y2 = 0.2;

  printf("%d %f %d %d %f\n", s.x1, s.y1, s.x2, s.x3, s.y2);

  m = &s;
  *m = 3;
  *(m+8) = 5;

  printf("%d %f %d %d %f\n", s.x1, s.y1, s.x2, s.x3, s.y2);

}
