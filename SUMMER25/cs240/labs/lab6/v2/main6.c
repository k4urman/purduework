// Command-line argument passing and loader invocation using execvp().

#include <stdio.h>
#include <unistd.h>

int main()
{
char *argv[] = {"ls","-l","-a",NULL};

  printf("%s\n", argv[0]);
  execvp(argv[0], argv); 
}
