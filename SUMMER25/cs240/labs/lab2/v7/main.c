// Pointers and arrays: 1-D array.

#include <stdio.h>

int main()
{
    int z[5];

    z[0] = 100;
    z[1] = 200;
    z[2] = 300;
    z[3] = 400;
    z[4] = 500;

    printf("%d\n", z[0]);
    printf("%d\n", z[1]);
    printf("%d\n", z[2]);
    printf("%d\n", z[3]);
    printf("%d\n", z[4]);

    printf("%d\n", *z);
    printf("%d\n", *(z + 1));
    printf("%d\n", *(z + 2));
    printf("%d\n", *(z + 3));
    printf("%d\n", *(z + 4));

    *z = 1;
    *(z + 1) = 2;
    *(z + 2) = 3;
    *(z + 3) = 4;
    *(z + 4) = 5;

    printf("%d\n", z[0]);
    printf("%d\n", z[1]);
    printf("%d\n", z[2]);
    printf("%d\n", z[3]);
    printf("%d\n", z[4]);

    printf("addy of z: %p\n", (void*)z);
    printf("addy of &z: %p\n", (void*)&z);

    return 0;
}
