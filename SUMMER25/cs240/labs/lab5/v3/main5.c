// Example to illustrate pointer to struct and use of malloc().

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
  char *name;
  int age;
  unsigned int cid;
} employee_t;


int main()
{
employee_t *alice;

  alice = (employee_t *) malloc(sizeof(employee_t));
  alice->name = (char *) malloc(strlen("Alice"));

  strcpy(alice->name, "Alice");
  alice->age = 29;
  alice->cid = 0;

  printf("%s\n",alice->name);
  printf("%d\n",alice->age);
  printf("%u\n",alice->cid);

}

