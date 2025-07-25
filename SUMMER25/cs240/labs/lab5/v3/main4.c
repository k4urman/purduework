// Example to illustrate pointer to struct and use of malloc().

#include <stdio.h>
#include <stdlib.h>

typedef struct employee {
  char name[8];
  int age;
  unsigned int cid;
} employee_t;


int main()
{
employee_t *alice;

  alice = (employee_t *) malloc(sizeof(employee_t));

  alice->name[0] = 'A';
  alice->name[1] = 'l';
  alice->name[2] = 'i';
  alice->name[3] = 'c';
  alice->name[4] = 'e';
  alice->name[5] = '\0';

  alice->age = 29;
  alice->cid = 0;

  printf("%s\n",alice->name);
  printf("%d\n",alice->age);
  printf("%u\n",alice->cid);

}

