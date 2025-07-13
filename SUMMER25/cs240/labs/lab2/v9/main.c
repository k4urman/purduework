// Pointers, memory, and silent run-time errors.

#include <stdio.h>

int main()
{
int s[5];
int i;

  for(i=0; i<5; i++)
	s[i] = i;

  for(i=0; i<5; i++)
  	printf("%d\n",s[i]);

  // doing something sketchy
  for(i=0; i<6; i++)
	s[i] = i;

  for(i=0; i<6; i++)
	printf("%d\n",s[i]);

}
