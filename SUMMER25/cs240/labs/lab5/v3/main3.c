// Example to illustrate struct and use of malloc().

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
employee_t bob;

  bob.name = (char *) malloc(strlen("Bob"));

  strcpy(bob.name, "Bob");

  bob.age = 22;
  bob.cid = 40;

  printf("%s\n",bob.name);
  printf("%d\n",bob.age);
  printf("%u\n",bob.cid);

}
