// Remove last name:
// function returns pointer.

#include <stdio.h>

char *firstname(char *);

int main()
{
char x[100];
char *y;

  x[0] = 'S';
  x[1] = 'u';
  x[2] = 'e';
  x[3] = ' ';
  x[4] = 'R';
  x[5] = 'a';
  x[6] = 'e';
  x[7] = '\0';

  printf("%s\n", x);

  y = firstname(x);

  printf("%s\n", y);

}


/* Return first name. */

char *firstname(char *s) {
int i;

  i = 0;
  while(s[i] != ' ')
	i++;

  s[i] = '\0';		// replace space with EOS

  return(s);
}
