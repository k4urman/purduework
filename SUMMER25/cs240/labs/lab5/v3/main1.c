// Example to illustrate C structure: struct.

#include <stdio.h>
#include <string.h>

struct employee {
  char name[8];
  int age;
  unsigned int cid;
};


int main()
{
struct employee alice;
struct employee bob;

  alice.name[0] = 'A';
  alice.name[1] = 'l';
  alice.name[2] = 'i';
  alice.name[3] = 'c';
  alice.name[4] = 'e';
  alice.name[5] = '\0';
  alice.age = 29;
  alice.cid = 0;

  printf("%s\n",alice.name);
  printf("%d\n",alice.age);
  printf("%u\n",alice.cid);

  strcpy(bob.name,"Bob");
  bob.age = 22;
  bob.cid = 40;

  printf("%s\n",bob.name);
  printf("%d\n",bob.age);
  printf("%u\n",bob.cid);

}
