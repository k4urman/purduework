// Example to illustrate function with variable number of arguments: first argument is
// a string as in printf() and counts the number of occurrences of %.

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

int main()
{
int myprintf(char *, ...);

  myprintf("%d %d %d %d", 10, 1, 5, 2);

}


int myprintf(char *a, ...)
{
int i, count = 0;
int s;
va_list arglist;

  va_start(arglist, a);

  while(*a != '\0') {
	if (*a == '%')
	  count++;
	a++;
  }

  printf("count = %d\n", count);

  for (i=0; i<count; i++) {
	s = va_arg(arglist, int);
	printf("%d\n", s);
  }

  va_end(arglist);

}
