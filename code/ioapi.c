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


// Will be one less \n at the start
void blankLineAfterPrompt() {

}
void blankLine() {
    printf("\n");
    blankLineAfterPrompt();
}

void blankSpace() {
    printf(" ");
}

void startLine() {
    printf(" >");
    blankSpace();
}

void say(char *text) {
    startLine();
    printf(text);
    blankLine();
}

void prompt(char *answer, char *prompt) {
    startLine();
    printf("%s\n", prompt);
    blankSpace();
    printf(" ; ");
    putNewLineIn(answer);
    blankLineAfterPrompt();
}


void start() {
    printf("\n");
    blankSpace();
    printf("text adventure >:)\n");
    blankLine();
}

void end() {
    blankLine();
    blankSpace();
    printf("adventure over ;(\n\n\n");
}