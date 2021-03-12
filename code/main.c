#include <stdio.h>
#include "userinput.h"

int main() {
    printf("greetings traveler!\n");
    printf("what is your name?\n;");
    char name[MAX_INPUT_LENGTH];
    putNewLineIn(name);
    printf("%s is a nice name!\n", name);
}