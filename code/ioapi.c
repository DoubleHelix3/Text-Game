#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ioapi.h"

void putNewLineIn(char *inputBuffer) {
    fgets(inputBuffer, MAX_INPUT_LENGTH, stdin);
    // get rid of that new line character at the end
    inputBuffer[strcspn(inputBuffer, "\n")] = 0;
}