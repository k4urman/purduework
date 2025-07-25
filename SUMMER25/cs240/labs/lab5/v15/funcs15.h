#ifndef FUNCS15_H
#define FUNCS15_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int packfile(FILE *input, FILE *output);
int unpackfile(int vbits, FILE *input, FILE *output);

#endif
