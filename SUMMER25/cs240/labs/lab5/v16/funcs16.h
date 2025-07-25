#ifndef FUNCS16_H
#define FUNCS16_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linesstruct {
  char *databytes;
  int id;
  int len;
  struct linesstruct *next;
};

typedef struct linesstruct linesstruct_t;

void linesinfo(char *, unsigned int *, unsigned int *);
void buildstruct(char *, int, struct linesstruct *);

#endif
