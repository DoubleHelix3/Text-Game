#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char *gotoBuildDir = "cd ../build";
    char *compile = " && gcc -c ../code/userinput.c";
    char *link = " && gcc -o main ../code/main.c userinput.o";
    
    int cmdLength = strlen(gotoBuildDir) + strlen(compile) + strlen(link);
    char *cmd = malloc(cmdLength*sizeof(char)); 
    strcat(cmd, gotoBuildDir);
    strcat(cmd, compile);
    strcat(cmd, link);
    // I have no idea why this needs to be here
    cmd+=3;
    printf("%s\n", cmd);
    
    system(cmd);
    return 0;
}