// Example to illustrate function with variable number of arguments.

#include <stdio.h>
#include <stdarg.h>

int mysum(int, ...);

int main()
{
int res;

  res = mysum(3, 10, 2, 5);
  printf("result = %d\n", res);

  res = mysum(5, 1, 99, 2, 98, 100);
  printf("result = %d\n", res);

}


int mysum(int a, ...)
{
int sum = 0; 
int i;
va_list arglist;

  va_start(arglist, a);

  for (i=0; i<a; i++)
	sum = sum + va_arg(arglist, int);

  va_end(arglist);

  return sum;

}
