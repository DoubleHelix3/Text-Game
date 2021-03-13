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

#define NEW_LINE "\n"
#define BLANK_SPACE "   "
#define INDICATOR "> "
#define PROMPT_INDICATOR "> "

void say(char *text) {
    printf("%s%s%s%s", NEW_LINE, BLANK_SPACE, INDICATOR, text);
}

void prompt(char *answer, char *prompt) {
    printf("%s%s%s%s\n%s", NEW_LINE, BLANK_SPACE, INDICATOR, prompt, BLANK_SPACE);
    printNTimes(" ", strlen(INDICATOR));
    printf(PROMPT_INDICATOR);
    putNewLineIn(answer);
    
    char *newLine = NEW_LINE;
    // get rid of first new line
    newLine[0] = ' ';
    print(newLine);
}


void start() {
    printf("\n%s", BLANK_SPACE);
    printf("text adventure ;)\n%s", NEW_LINE);
}

void end() {
    printf("%s%sadventure over ;(\n\n\n", NEW_LINE, BLANK_SPACE);
}