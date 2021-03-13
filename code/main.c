#include <stdlib.h>
#include <stdio.h>

#include "ioapi.h"

int main() {
    char in[MAX_INPUT_LENGTH];
    char out[MAX_OUTPUT_LENGTH];

    start();

    say("greetings traveler!");

    prompt(in, "what is your name?");
    sprintf(out, "%s is a nice name.", in);
    say(out);
    
    prompt(in, "where are you from?");
    sprintf(out, "%s is a really far off land.", in);
    say(out);
    
    end();
    
    return 0;
}