#include "userinput.h"
#include <stdio.h>
#include <string.h>

void putNewLineIn(char *str) {
    fgets(str, MAX_INPUT_LENGTH, stdin);
    // get rid of that new line character at the end
    str[strcspn(str, "\n")] = 0;
}