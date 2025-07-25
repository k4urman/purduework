// Use of command-line arguments.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
int i;

  fprintf(stdout,"I am a.out (%d): part I\n", getpid());

  execl("/homes/park/pub/cs240/lab5/v1/outputargs", "/homes/park/pub/cs240/lab5/v1/outputargs", 
	"one", "-l", "-c", "TWO", "-gaux", NULL);

  fprintf(stdout,"I am a.out (%d): part II\n", getpid());

}
