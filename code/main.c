#include <stdlib.h>
#include <stdio.h>

#include "ioapi.h"

int main() {
    char text[500];

    blankLine();
    say("greetings traveler!");

    char name[MAX_INPUT_LENGTH];
    prompt(name, "what is your name?");
    sprintf(text, "%s is a nice name.", name);
    say(text);
    
    char place[MAX_INPUT_LENGTH];
    prompt(place, "where are you from?");
    sprintf(text, "%s is a really far off land.", place);
    say(text);
    blankLine();

    return 0;
}