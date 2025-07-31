// Command-line argument passing and loader invocation using execve().

#include <stdio.h>
#include <unistd.h>

int main()
{
char *argv[] = {"/bin/ls","-l","-a",NULL};

  execve(argv[0], argv, NULL); 
}
