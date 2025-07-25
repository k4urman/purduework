// Example to illustrate typedef.

#include <stdio.h>

typedef struct employee {
  char name[8];
  int age;
  unsigned int cid;
} employee_t;


int main()
{
employee_t bob;

  bob.name[0] = 'B';
  bob.name[1] = 'o';
  bob.name[2] = 'b';
  bob.name[3] = '\0';
  bob.age = 22;
  bob.cid = 40;

  printf("%s\n",bob.name);
  printf("%d\n",bob.age);
  printf("%u\n",bob.cid);

}
