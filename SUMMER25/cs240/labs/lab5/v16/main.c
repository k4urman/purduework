#include "funcs16.h"

/*
 * takes in arguments from command line. Will be a repetitive loop
 * until terminated.
 */

int main(int argc, char *argv[]) {
  // makes sure that the arguments are the right amount or else give error
  if (argc < 2 || argc > 3) {
    fprintf(stderr, "not the right typpe of args (mode) <input file> [output file]\n");
    exit(1);
  }

  // tyhe variables for the files. outfil only there if it exists, otherwise, not used.
  char *infile = argv[1];
  char *outfile = (argc == 3) ? argv[2] : NULL;

  // important variables
  unsigned int nlines = 0;
  unsigned int maxline = 0;

  // linesinfo
  linesinfo(infile, &nlines, &maxline);

  // create the data structure and allocate memeory, otherwise error
  linesstruct_t *data = malloc(nlines * sizeof(linesstruct_t));
  if (data == NULL) {
    fprintf(stderr, "Error: cannot allocate memory for linesstruct_t\n");
    exit(1);
  }

  // create the structure after allocation by calling buildstruct
  buildstruct(infile, maxline, data);

  // important variables
  char cmd;
  int c;

  // endless loop until termination
  while (1) {
    // always printing with Q: in the front
    fprintf(stderr, "Q: ");
    // grabs the user input
    cmd = getchar();

    // if loops were too long so we used switch cases from user input
    switch (cmd) {
        // quit command. All prior changes made will not be saved anywhere else.
      case 'q':
        c = getchar();
        if (c == '\n') {
          for (unsigned int i = 0; i < nlines; i++) {
            if (data[i].databytes != NULL) {
              free(data[i].databytes);
            }
          }
          free(data);
          exit(0);
        } else {
          // invalid command error message given
          fprintf(stderr, "Error: invalid cmd ask\n");
        }
        break;

        // delete case!
      case 'd':
        // first make sure that the d is not empty
        c = getchar();
        if (c != ' ') {
          fprintf(stderr, "Error:invalid delete cmd ask\n");
          while (c != '\n' && c != EOF) {
            c = getchar();
          }
          break;
        }

        /*
         * we give a 32 buffer with an index. If not a digit for which line
         * we give an error. finally, we turn the number beffer of the line
         * into an int using atoi. Make sure the line exists. Then proceed
         * to remove that line and index the next line is there up front to
         * take it's index.
         */
        char numbuf[32];
        int idx = 0;
        c = getchar();

        if (!isdigit(c)) {
          fprintf(stderr, "Error: invalid linenum ask\n");
          while (c != '\n' && c != EOF) {
            c = getchar();
          }
          break;
        }

        while (isdigit(c) && idx < 31) {
          numbuf[idx++] = c;
          c = getchar();
        }
        numbuf[idx] = '\0';

        if (c != '\n') {
          fprintf(stderr, "Error: nvalid delete cmd ask\n");
          while (c != '\n' && c != EOF) {
            c = getchar();
          }
          break;
        }

        int dline = atoi(numbuf);

        if (dline < 0 || dline >= (int)nlines) {
          fprintf(stderr, "Error: invalid linenum\n");
          break;
        }

        data[dline].id = -1;
        break;

        /* save! save takes all changes and either changes input, or output if
         * given. the data struct made in main will be changed for each value
         * to be changed to mathc the output and hold the changes that we
         * have made. We close the temporary files and free any allocation.
         */
      case 's':
        c = getchar();
        if (c == '\n') {
          char *savefile = (outfile != NULL) ? outfile : infile;

          FILE *savefp = fopen(savefile, "w");
          if (savefp == NULL) {
            fprintf(stderr, "Error: failed to open file 4 writing\n");
            exit(1);
          }

          for (unsigned int i = 0; i < nlines; i++) {
            if (data[i].id != -1) {
              fprintf(savefp, "%s", data[i].databytes);

              if (data[i].next != NULL) {
                fprintf(savefp, "%s", data[i].next->databytes);
              }
            }
          }

          fclose(savefp);

          for (unsigned int i = 0; i < nlines; i++) {
            if (data[i].databytes != NULL) {
              free(data[i].databytes);
            }
          }

          free(data);
          exit(0);

        } else {
          fprintf(stderr, "Error: invalid cmd ask\n");
          while (c != '\n' && c != EOF) {
            c = getchar();
          }
        }
        break;

        /*Join! used to, as the name suggests, a line to the file*/
      case 'j':
        // you cannot join an empty string to file so error
        c = getchar();
        if (c != ' ') {
          fprintf(stderr, "Error: invalid join cmd ask\n");
          while (c != '\n' && c != EOF) {
            c = getchar();
          }
          break;
        }
        // just as before, we have buffers and indices for the file as we get char
        char joinbuf1[32];
        int jidx = 0;
        c = getchar();

        // if not a digit after j, we give error
        if (!isdigit(c)) {
          fprintf(stderr, "Error: invalid 1st linenum ask\n");
          while (c != '\n' && c != EOF) {
            c = getchar();  // otherwise get char
          }
          break;
        }

        // otherwise we loop through the buffer index and = to c
        while (isdigit(c) && jidx < 31) {
          joinbuf1[jidx++] = c;
          c = getchar();
        }
        joinbuf1[jidx] = '\0';  // null terminate last

        // cannot ask for a space
        if (c != ' ') {
          fprintf(stderr, "Error: invalid join cmdask\n");
          while (c != '\n' && c != EOF) {
            c = getchar();
          }
          break;
        }

        // second buffer and index
        char joinbuf2[32];
        jidx = 0;
        c = getchar();

        if (!isdigit(c)) {
          fprintf(stderr, "Error: invalid 2nd linenum ask\n");
          while (c != '\n' && c != EOF) {
            c = getchar();
          }
          break;
        }

        while (isdigit(c) && jidx < 31) {
          joinbuf2[jidx++] = c;
          c = getchar();
        }
        joinbuf2[jidx] = '\0';

        if (c != '\n') {
          fprintf(stderr, "Error: invalid join cmd ask\n");
          while (c != '\n' && c != EOF) {
            c = getchar();
          }
          break;
        }

        // after repeating for second buffer, we get the buffer to ints
        int l1 = atoi(joinbuf1);
        int l2 = atoi(joinbuf2);

        // if l's are somehow wrong, we give an error (saftey precaution)
        if (l1 < 0 || l1 >= (int)nlines || l2 < 0 || l2 >= (int)nlines) {
          fprintf(stderr, "Error: invalid linenum)\n");
          break;
        }

        // no neg number
        if (data[l1].id == -1 || data[l2].id == -1) {
          fprintf(stderr, "Error: cannot join dellines\n");
          break;
        }

        // no null or error
        if (data[l1].next != NULL) {
          fprintf(stderr, "Error: annot join 2+ lines\n");
          exit(1);
        }

        // loop through and make sure the index is not already in use
        for (unsigned int check = 0; check < nlines; check++) {
          if (data[check].next == &data[l2] && check != (unsigned int)l1) {
            fprintf(stderr, "Error: line joined to another line already \n");
            goto jdone;
          }
        }

        // otherwise, join the two via struct connection
        data[l1].next = &data[l2];
        data[l2].id = -1;

      jdone:
        break;
        // view!
      case 'v':
        c = getchar();

        // make sure c is not newline before proceeding
        if (c == '\n') {
          // for each line , we will iterate after each newline print the string with the number, aka the index
          for (unsigned int i = 0; i < nlines; i++) {
            if (data[i].id != -1) {
              printf("%s", data[i].databytes);
              if (data[i].next != NULL) {
                printf("%s", data[i].next->databytes);
              }
            }
          }
        } else if (c == ' ') {  // print entire thing cause no index
          char viewbuf[32];
          int vidx = 0;
          c = getchar();

          // not a digit? well give an error.

          if (!isdigit(c)) {
            fprintf(stderr, "Error: invalid linenum ask\n");
            while (c != '\n' && c != EOF) {
              c = getchar();
            }
            break;
          }

          /*if it is a digit then we make each eahc buffer char
           * equal to c and get each char. The very end should be null
           * terminated since it is strings.*/
          while (isdigit(c) && vidx < 31) {
            viewbuf[vidx++] = c;
            c = getchar();
          }
          viewbuf[vidx] = '\0';

          /*
           * we will break once the view gets a newline for all
           */
          if (c != '\n') {
            fprintf(stderr, "Error: invalid view cmd ask\n");
            while (c != '\n' && c != EOF) {
              c = getchar();
            }
            break;
          }

          int vline = atoi(viewbuf);  // counter

          // cannot be negative or above line count else error
          if (vline < 0 || vline >= (int)nlines) {
            fprintf(stderr, "Error: invalid linenum\n");
            break;
          }

          // some deleted lines cause errors. We can handle that
          // by creating a error statement that checks the struct data
          if (data[vline].id == -1) {
            fprintf(stderr, "Error: line has been deleted\n");
            break;
          }

          // each line printed
          printf("%s", data[vline].databytes);

          // next pointer connected will be printed
          if (data[vline].next != NULL) {
            printf("%s", data[vline].next->databytes);
          }
        } else {  // else error
          fprintf(stderr, "Error: invalid cmd ask\n");
          while (c != '\n' && c != EOF) {
            c = getchar();
          }
        }
        break;

        // give new Q: if given space.
      case '\n':
        break;

        // the default is if the command is not known, we give an error
      default:
        fprintf(stderr, "Error: idk command '%c'\n", cmd);
        c = getchar();
        while (c != '\n' && c != EOF) {
          c = getchar();
        }
        break;
    }
  }

  // retutm for main
  return 0;
}
