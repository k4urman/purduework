// Command-line argument passing and loader invocation using execvp().

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
char **x;

  // argv[0] contains a.out, need to pass argv[1] onwards;
  // use x to point to argv[1].
  x = ++argv;
  execvp(x[0], x); 
}
