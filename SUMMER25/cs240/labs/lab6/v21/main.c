#include "funcs21.h"  //header file with all the important stuff
// MORE IN DEPTH ANALYSIS ANNOTATION IN README

// copy prompt copies the prompt to a dest holder
void copyprompt(char *dest, char *src) {
  int i = 0;
  while (i < MAX_PROMPT - 1 && src[i]) {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
}

int main() {
  // prompt because %% caused errors
  // initilize the prompt and cmd
  char prompt[MAX_PROMPT] = "% ";
  char cmd[MAX_CMD];

  while (1) {
    printf("%s ", prompt);

    // if error, break
    if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
      break;
    }

    // if user command is e, exit.
    if (cmd[0] == 'e' && cmd[1] == '\n') {
      exit(0);
    }  // if use command is copy string
    else if (cmd[0] == 'c' && cmd[1] == ' ') {
      // holds the string after c for copy
      char *newp = cmd + 2;
      int len = 0;  // size of the string that will be traversed

      //find length of the string
      while (newp[len] && newp[len] != '\n') {
        len++;
      }

      // make sure it does not go over our max
      if (len > MAX_PROMPT - 1) {
        fprintf(stderr, "Error: input too long (max 11 chars)\n");
      } else {
        int valid = 1;  // makes sure valid
        for (int i = 0; newp[i] && newp[i] != '\n'; i++) {
          char c = newp[i];
          if (!isalnum(c) && c != ':' && c != '>' && c != '@' && c != '$' &&
              c != '%' && c != ' ' && c != '\t') {
            valid = 0;
            break;  // if not valid, break for error
          }
        }
        if (valid) {
          copyprompt(prompt, newp);  // copies the string to prompt
        } else {
          fprintf(stderr, "Error: invalid character iinputted\n");
        }
      }
    } else if (cmd[0] == 'l' && cmd[1] == '\n') {
      char *args[] = {"/bin/ls", NULL};
      pid_t k = fork();
      if (k == 0) {
        execvp(args[0], args);
        fprintf(stderr, "error executing /bin/ls\n");
        exit(1);
      }
    } else if (cmd[0] == 'L' && cmd[1] == '\n') {  // print the ls -l
      char *args[] = {"/bin/ls", "-l", NULL};
      pid_t k = fork();
      if (k == 0) {  // forks
        execvp(args[0], args);
        fprintf(stderr, "error executing /bin/ls -l\n");
        exit(1);
      }
    } else if (cmd[0] == 'j' && cmd[1] == '\n') {  // prints the joke
      char *args[] = {"/bin/cat", "joke.dat", NULL};
      pid_t k = fork();
      if (k == 0) {  // fork
        execvp(args[0], args);
        fprintf(stderr, "error reading joke.dat\n");
        exit(1);
      }
    } else {  // this is to go for other commands
      char *args[MAX_CMD];
      int aindex = 0;
      int token = 0;
      int tindex = 0;

      for (int i = 0; cmd[i] != '\0'; i++) {
        if (cmd[i] == ' ' || cmd[i] == '\n') {
          if (token) {
            cmd[i] = '\0';
            args[aindex++] = &cmd[tindex];
            token = 0;
          }
        } else if (!token) {
          tindex = i;
          token = 1;
        }
      }
      args[aindex] = NULL;

      pid_t k = fork();
      if (k == 0) {
        execvp(args[0], args);
        fprintf(stderr, "Error: cmd not found\n");
        exit(1);
      }
    }
    sleep(2);
  }

  return 0;
}
