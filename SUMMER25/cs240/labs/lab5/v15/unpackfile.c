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


        for (int i = vbits; i >= 0; i--) {
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
