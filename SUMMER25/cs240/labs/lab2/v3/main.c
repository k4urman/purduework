// Local vs. global variable.

#include <stdio.h>

void one(void);
void two(void);

int a = 1;
int b = 2;

int main()
{

  one();
//  two();
  one();
//  two();
  one();

}


void one()
{

  printf("%d %d\n", a, b);
}


void two()
{
int a, b;

  a = 1000;
  b = 2000;
  printf("%d %d\n", a, b);
}
