#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char *compile = " && gcc -c ../code/userinput.c";
    char *link = " && dir"; 
    // gcc -o ../code/main.c userinput.o
    char *cmd = "cd ../build";
    strcat(cmd, compile);
    system(cmd);
    strcat(cmd, link);
    system(cmd);
    return 0;
}