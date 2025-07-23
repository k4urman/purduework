#include "funcs15.h"

/*main takes in command line arguments right after the ./ */
int main(int argc, char** argv)
{
  // two FILE objects that will hold in input and output funcstions
  FILE *input;
  FILE *output;

  /*
   * there can only be up to 3 arguments and if there are more,
   * then we have an issue and we print out an error.
   */
  if (argc != 4) {
    fprintf(stderr, "Error: too many or too little args given. \n");
    exit(1);
  }

  /* we only have two modes: pack and unpack
   * if user gives anything else we give an error*/

  if (!(argv[1][0] == 'u' || argv[1][0]  == 'p')) {
    fprintf(stderr, "Error: not a mode given as mode, only use p or u.\n");
    exit(1);
  }

  /*now we will open the two files and if they are unable to be
   * opened we will give an error.*/
  input = fopen(argv[2], "r");
  output = fopen(argv[3], "w");

  if (input == NULL) {
    fprintf(stderr, "Error: cannot open input file.\n");
    exit(1);
  }
  if (output == NULL) {
    printf("Error:cannot open output file\n");
    exit(1);
  }


  /*
   * the very first arg is the mode and we check that right now with
   * argv and if it is p, we will simply packfile. Unpackfile is the one
   * that needs more work. We will print a success if done, initially tested
   * printing what the packfile returns to make sure before closing.
   * */
  if (argv[1][0] == 'p') {
    packfile(input, output);
    printf("success! compressed input file!\n");

    fclose(input);
    fclose(output);
  }

  /*
   * now on the other hand, if unpack is chosen we first get two variables, one
   * which gets the last and the other that gets the 2nd to last. we read in
   * from input and while the file doesn not end, we continue parsing to get the
   * ltwo final.
   *
   * Now we have to repon the file bc we need to be back at the front of the
   * file. This time we have all the valid bits from ltwo and the two files to
   * take unpack and unpack onto. finally, we close.
   */
  if (argv[1][0] == 'u') {
    int ltwo = fgetc(input);
    int last = fgetc(input);
    while (last != EOF) {
      ltwo = last;
      last = fgetc(input);
    }

    fclose(input);
    input = fopen(argv[2], "r");

    if (input == NULL) {
      fprintf(stderr, "Error:cannot reopen input file  \n");
      exit(1);
    }

    unpackfile(ltwo - 1, input, output);
    fprintf(stderr, "success! expanded file given!\n");

    fclose(input);
    fclose(output);
  }

  // return for main
  return 0;
}
#include "funcs15.h"

/*
 * packfile gets two files, one to read the string, and another
 * to unload the read string into binary file.
 */
int packfile(FILE *input, FILE *output) {
    /*
     * some important variables for later.
     */

    int c = fgetc(input);
    unsigned int r = 0;
    int bicount = 0;
    int tbytes = 0;

    /*
     * c reads in the input file. First: make sure it not NULL, otherwise, give
     * an error.
     */
    if (c == EOF) { //
        fprintf(stderr, "Error: input is empty\n");
        exit(1);
    }

    /*
     * until we reach the end of the file, we keep reading each 1 or 0. Make
     * sure that it is ONLY those two, otherwise give an error.
     *
     * We then proceed to shift to the left for a new bit and add it.
     * repeat until out bit counter is above 8, bc that means we have a full
     * byte and we place the bit shift to the output before going onto next.
     */
    while (c != EOF) {
        if (!(c == '1' || c == '0')) {
            fprintf(stderr, "Error: input has char that is not 0 or 1. \n");
            exit(1);
        }

        r = (r << 1);
        if (c == '1') {
            r = r | 1;
        }
        bicount++;

        if (bicount == 8) {
            fputc(r, output);
            tbytes++;
            r = 0;
            bicount = 0;
        }
      c = fgetc(input);
    }

 /*
  * Soimtimes, input is not exactly %8 = 0. Because of that, there are
  * remainders we will deal with. the remaining will be shifted all the way to
  * the left to stuff the byte full before writing tge kast byte.
  */
    if (bicount > 0) {
        r = r << (8 - bicount);
        fputc(r, output);
        tbytes++;

        fputc(bicount, output);
        tbytes++;
    }else {
        fputc(8, output);
        tbytes++;
    }

    /*return total num of bytes we have, num/8 ceiling*/
    return tbytes;
}

#include "funcs15.h"

/*
 * unpackfile does the opposite of packfile. It gets a binary file input,
 * which we can't see because we are not in binary read/write mode,
 * and turns it into a binary string in output.
 */

int unpackfile(int vbits,FILE *input,FILE *output) {

  // important variables for later
    int c = fgetc(input);

    int nextbyte = fgetc(input);

    int tbytes = 0;


    /*
     * we will read each bit in the input first, having x work as one that
     * looks ahead to the next byte without replacing c or nextbyte when needed
     * initially. Keep going till the end, otherwise stop. If the bit is 1, we
     * print 1 into output, 0 otherwise, before moving the c, nextbyte, and x.
     */

    while (nextbyte != EOF) {
        int x = fgetc(input);
        if (x == EOF) {
            break;
        }


        for (int i = 7; i >= 0; i--) {
            if (((c >> i) & 1) == 1) {
                fputc('1', output);
            } else {
                fputc('0', output);
            }
        }

        c = nextbyte;
        nextbyte = x;
        tbytes++;
    }

    /*
     * the last bit is important as we will use vbits. Only if it is not EOF.
     * We read if the last bit is 1 or 0 and print it out into output. For each
     * loop complete, we will increment the total bytes (input / 8 ceiling)
     */
    if (c != EOF) {

        int valid = (vbits == 0) ? 8 : vbits;


        for (int i = 7; i >= 8 - valid; i--) {
            if (((c >> i) & 1) == 1) {
                fputc('1', output);
            } else {
                fputc('0', output);
            }
        }
        tbytes++;
    }

    /*return total bytes*/
    return tbytes;
}
