#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

void userInput(char **str) {
    fgets(*str, MAX_INPUT_LENGTH, stdin);
    // get rid of that new line character at the end
    *str[strcspn(*str, "\n")] = 0;
}