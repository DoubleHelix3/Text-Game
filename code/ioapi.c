#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void putNewLineIn(char *textBuffer, int maxInputLength) {
    fgets(textBuffer, maxInputLength, stdin);
    // get rid of that new line character at the end
    textBuffer[strcspn(textBuffer, "\n")] = 0;
}