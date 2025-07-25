// Use of command-line arguments: environment variable.

#include <stdio.h>

int main(int argc, char **argv, char **env)
{
int i;

  while (*env != NULL) {
	printf("%s\n", *env);
	env++;
  }

}
