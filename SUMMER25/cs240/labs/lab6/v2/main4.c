// Simple shell example using fork() and execl().

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
pid_t k;
char buf[100];
int status;
int len;

  while(1) {

	// print prompt
  	fprintf(stdout,"%d%% ",getpid());

	// improved reading of user input
	fgets(buf, 100, stdin);

	// does fgets() store '\n' when pressing ENTER/RET key?
	len = strlen(buf);
	if(len == 1) 
	  continue;
	buf[len-1] = '\0';

	// create worker process
  	k = fork();
  	if (k==0) { // child code
    	  execl(buf,buf,NULL);
  	}
  	else { // parent code 
	  waitpid(k, &status, 0);
  	}
  }
}
