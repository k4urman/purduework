// Simple shell example using fork() and execl().

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main()
{
pid_t k;
char buf[100];
int status;
int len;

  while(1) {

	// print prompt
  	fprintf(stdout,"%d $ ",getpid());

	// read user command
	fgets(buf, 100, stdin);

	len = strlen(buf);
	if(len == 1)	// only ENTER/RET key pressed
	  continue;
	buf[len-1] = '\0'; // shift EOS to where '\n' is stored

	// create worker bee
  	k = fork();
  	if (k==0) { // child code
    	  if(execl(buf,buf,NULL) == -1)  // loader can fail: if so terminate worker process
	  	exit(1);
  	}
  	else { // parent code 
	  waitpid(k, &status, 0);
  	}
  }
}
