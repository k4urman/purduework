#include <stdio.h>

#define LENUP 12
#define ERRINPUT -1

int readinput(char *inputstr);
void printoutput(int count, char *inputstr);

int main() {
    char inputstr[LENUP];
    int result = readinput(inputstr);

    if (result == ERRINPUT) {
        printf("Error\n");
        return 1;
    }

    printoutput(result, inputstr);
    return 0;
}
