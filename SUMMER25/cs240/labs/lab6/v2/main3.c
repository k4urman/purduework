// Simple shell example using fork() and execl().

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
	fscanf(stdin,"%s",buf);

	// create worker process
  	k = fork();

  	if (k==0) { // child code
	  // invoke loader
    	  execl(buf,buf,NULL);
  	}
  	else { // parent code 
	  // wait for child process to terminate
	  waitpid(k, &status, 0);
  	}
  }
}
