#ifndef HEADER5_H
#define HEADER5_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findsize(char *inputfile);
void readvectors(int n, char *inputfile, int *u, int *v);
void outprodcalc(int n, int *u, int *v, int **z);
void printres(int n, int **z);

#endif // HEADER5_H
