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
