#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ioapi.h"

void putNewLineIn(char *str) {
    fgets(str, MAX_INPUT_LENGTH, stdin);
    // get rid of that new line character at the end
    str[strcspn(str, "\n")] = 0;
}

void printNTimes(char *str, int n) {
    for(int i=0; i<n; i++) printf(str);
}

const char *NEW_LINE = "\n";
const char *BLANK_SPACE = "   ";
const char *INDICATOR = "* ";
const char *PROMPT_INDICATOR = "> ";

void say(char *text) {
    printf("%s%s%s%s", NEW_LINE, BLANK_SPACE, INDICATOR, text);
}

void prompt(char *answer, char *prompt) {
    printf("%s%s%s%s\n%s", NEW_LINE, BLANK_SPACE, INDICATOR, prompt, BLANK_SPACE);
    printNTimes(" ", strlen(INDICATOR));
    printf(PROMPT_INDICATOR);
    putNewLineIn(answer);
    
    char *newLine = malloc(strlen(NEW_LINE)*sizeof(char));
    strcpy(newLine, NEW_LINE);
    // gets rid of first new line character
    newLine++;
    printf(newLine);
    free(newLine);
}

void startGame() {
    printf("\n%s", BLANK_SPACE);
    printf("text adventure ;)%s", NEW_LINE);
}

void endGame() {
    printf("\n%s%sadventure over ;(\n\n", NEW_LINE, BLANK_SPACE);
}