#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <dirent.h>

#define BUILD_FOLDER_PATH "..//build"
#define CODE_FOLDER_PATH "..//code"

void build(char **files) {
    int cmdLength = strlen(BUILD_FOLDER_PATH) + 2*strlen(CODE_FOLDER_PATH) + 64;
    char *cmd = malloc(cmdLength*sizeof(char));
    *cmd = '\0';
    strcat(cmd, "cd ");
    strcat(cmd, BUILD_FOLDER_PATH);
    strcat(cmd, " && gcc -c ");
    strcat(cmd, CODE_FOLDER_PATH);
    strcat(cmd, "\\userinput.c && gcc -o main ");
    strcat(cmd, CODE_FOLDER_PATH);
    strcat(cmd, "\\main.c userinput.o");

    system(cmd);
}

char **getFiles() {
    DIR *dp;
    struct dirent *ep;

    dp = opendir(CODE_FOLDER_PATH);
    if(dp == NULL) perror("Couldn't open the directory"); 
    
    int totalFileNamesSize = 0;
    while(ep = readdir(dp)) {
        char *filename = ep->d_name;
        totalFileNamesSize += strlen(filename);
    }

    char **files = malloc(totalFileNamesSize*sizeof(char));

    int i = 0;
    while(ep = readdir(dp)) {
        char *filename = ep->d_name;
        int len = strlen(filename);
        if(filename[len-1] == '\n') files[++i] = filename;
    }

    (void) closedir(dp);
    
    return files;
}

int main() {
    char **files = getFiles();
    build(files);

    return 0;
}