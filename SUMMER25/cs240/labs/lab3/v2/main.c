// Static variables: persistence across multiple function calls.

#include <stdio.h>

int fun(void);

int main() {
int x;

  x = fun();
  printf("%d\n",x);

  x = fun();
  printf("%d\n",x);

  x = fun();
  printf("%d\n",x);

}


int fun() {
static int y = 5;

  return ++y;
  // what about y++?
}
