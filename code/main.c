#include <stdio.h>
#include "userinput.h"

int main() {
    printf("Greetings traveler!\n");
    printf("What is your name?\n-");
    char name[MAX_INPUT_LENGTH];
    userInput(name);
    printf("%s is a nice name!\n", name);
    return 0;
}