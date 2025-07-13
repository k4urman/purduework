#include <stdio.h>
#include "mystrlen.h"

int main() {
    char *testStrings[] = {
        "hello",
        "world",
        "C programming",
        "mystrlen",
        "",
        "123456789",
	"1234567890"
    };

    for (int i = 0; i < 7; i++) {
        printf("length of \"%s\" is: %d\n", testStrings[i], mystrlen(testStrings[i]));
    }

    return 0;
}
