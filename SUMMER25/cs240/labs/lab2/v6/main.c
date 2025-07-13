// Basic method to locate where in code run-time error occurs.

#include <stdio.h>

// new C preprocessor directive
#define DEBUGFLAG

void abc(int *);

int main()
{
int x;

  x = 5;
  printf("%d\n",x);

#ifdef DEBUGFLAG
printf("ok 1\n");
#endif

  abc(&x);

#ifdef DEBUGFLAG
printf("ok 2\n");
#endif

  printf("%d\n",x);

#ifdef DEBUGFLAG
printf("ok 3\n");
#endif

  abc(x);

#ifdef DEBUGFLAG
printf("ok 4\n");
#endif

  printf("%d\n",x);

}


void abc(int *s)
{
  *s = 1000;
}
