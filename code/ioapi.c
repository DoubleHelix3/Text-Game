#include <stdio.h>
#include <string.h>

#include "ioapi.h"

void putNewLineIn(char *str) {
    fgets(str, MAX_INPUT_LENGTH, stdin);
    // get rid of that new line character at the end
    str[strcspn(str, "\n")] = 0;
}

void putMultipleTimes(char *s, int n) {
    for(int i=0; i<n; i++) {
        printf(s);
    }
}

void blankLine() {
    printf("\n");
}

void blankSpace() {
    printf(" ");
}

void say(char *text) {
    printf(" >");
    blankSpace();
    printf(text);
    blankLine();
}

void prompt(char *answer, char *prompt) {
    say(prompt);
    blankSpace();
    printf(" ; ");
    putNewLineIn(answer);
}