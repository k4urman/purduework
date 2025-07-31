// Example to illustrate function with variable number of arguments: first argument is
// a string as in printf(), counts the number of occurrences of %, and // checks for 
// type of input: %d, %s, %d, %c

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
char x = 'A';
int y = 9;
int myprintf(char *, ...);


  myprintf("%c %d %s %d %f %c", x, y, "howdy", 111, 9.6, 'B');

}


int myprintf(char *a, ...)
{
int x;
char *y;
double z;
char m;
char numb[100];
va_list arglist;

  va_start(arglist, a);

  while(*a != '\0') {
	if (*a == '%') {
	  switch (*(a+1)) {
		case 'd':
			x = va_arg(arglist, int);
			printf("%d\n", x);			
			break;
		case 's':
			y = va_arg(arglist, char *);
			printf("%s\n", y);			
			break;
		case 'f':
			z = va_arg(arglist, double);
			printf("%f\n", z);			
			break;
		case 'c':
			m = va_arg(arglist, int);
			printf("%c\n", m);			
			break;
		default:
			continue;
	  }
	}
	a++;
  }

  va_end(arglist);

}
