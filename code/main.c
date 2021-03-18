#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ioapi.h"

typedef char bool;
#define false (bool) 0
#define true (bool) 1

typedef struct {
    char *name;
    int dmg;
} Move;

Move createMove(char *name, int dmg) {
    return (Move) {name, dmg};
}



bool handleMoves(char *input, int movesLength, Move moves[]) {
    for(int i=0; i<movesLength; i++) {
        char text[100];
        *text = 0;
        strcat(text, "info ");
        strcat(text, moves[i].name);
        if(!strcmp(input, text)) {
            printf("damage %d\n", 10);
            return true;
        }
    }


    if(!strcmp(input, "moves")) {
        for(int i=0; i<movesLength; i++) {
            printf("%s\n", moves[i].name);
        }

        return true;
    }

    return false;
}

bool handleCombat(char *input, int movesLength, Move moves[], bool *inCombat, int *enemy) {
    bool isCombatCommand = false;
    char *printBuffer = malloc(100*sizeof(char));
    *printBuffer = 0;
    if(!strcmp(input, "enemy")) {
        sprintf(printBuffer, "enemy %d\n", *enemy);
        isCombatCommand = true;
    }

    for(int i=0; i<movesLength; i++) {
        if(!strcmp(input, moves[i].name)) {
            *enemy -= moves[i].dmg;
            strcat(printBuffer, "enemy hit\n10 damage dealt\n");
            
            isCombatCommand = true;
        }
    }

    bool inCombatBefore = *inCombat;
    if(*enemy <= 0) {
        strcat(printBuffer, "enemy defeated\n");
        *inCombat = false;
    }

    if(inCombatBefore) printf(printBuffer);
    free(printBuffer);

    return isCombatCommand;
}

int main() {
    int inputLength = 100;
    char input[100];

    int movesLength = 1;
    Move moves[] = {createMove("punch", 10)};
    
    int enemy = 20;

    char *invalidInputBuffer = malloc(100*sizeof(char));
    bool inCombat = 1;
    while(1) {
        *invalidInputBuffer = 0;
        strcat(invalidInputBuffer, "invalid input\n");

        printf("> ");
        putNewLineIn(input, inputLength);

        if(handleMoves(input, movesLength, moves)) {
            *invalidInputBuffer = 0;
        }

        bool inCombatBefore = inCombat;
        bool isCombatCommand = handleCombat(input, movesLength, moves, &inCombat, &enemy);
        if(isCombatCommand) {
            if(inCombatBefore) {
                *invalidInputBuffer = 0;
            } else {
                *invalidInputBuffer = 0;
                strcat(invalidInputBuffer, "invalid input\n");
                strcat(invalidInputBuffer, "not in combat\n");
            }
        }
        
        if(!strcmp(input, "")) *invalidInputBuffer = 0;

        printf(invalidInputBuffer);
    }
    free(invalidInputBuffer);

    return 0;
}