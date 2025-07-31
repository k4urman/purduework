// Example to illustrate function with variable number of arguments: 
// first argument is a string similar to printf().

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int main()
{
int mysum(char *, ...);
int res;

  res = mysum("AmZzp", 10, 1, 10, 5, 2);
  printf("result = %d\n", res);

}


int mysum(char *a, ...)
{
int sum = 0, i; 
int cnt;
va_list arglist;

  va_start(arglist, a);
  cnt = strlen(a);
  printf("string length: %d\n", cnt);

  for (i=0; i<cnt; i++)
	sum += va_arg(arglist, int);

  va_end(arglist);

  return sum;

}
