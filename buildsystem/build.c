#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <dirent.h>

const char *BUILD_FOLDER_PATH = "..\\build";
const char *CODE_FOLDER_PATH "..\\code";

void build(char **files, int count, int totalFileNamesSize) {
    // We're going to create a command that does everything for us, then run that command
    int cmdLength = count*(strlen(CODE_FOLDER_PATH)+10) + 2*totalFileNamesSize + 100;
    char *cmd = malloc(cmdLength*sizeof(char));
    *cmd = '\0';
    
    char text[100];

    sprintf(text, "cd %s", BUILD_FOLDER_PATH);
    strcat(cmd, text);
    strcat(cmd, " && del * /q");

    strcat(cmd, " && gcc -c ");
    for(int i=0; i<count; i++) {
        sprintf(text, "%s\\%s ", CODE_FOLDER_PATH, files[i]);
        strcat(cmd, text);
    }

    sprintf(text, " && gcc -o main %s\\main.c ", CODE_FOLDER_PATH);
    strcat(cmd, text);
    for(int i=0; i<count; i++) {
        // the .c files will have extension .o after compilation
        char *ofile = files[i];
        int ofileLen = strlen(ofile);
        ofile[ofileLen-1] = 'o';
        strcat(cmd, ofile);
        strcat(cmd, " ");
    }

    system(cmd);
}

void getFiles(char ***put, int *count, int *totalFileNameSizePtr) {
    DIR *dp;
    struct dirent *ep;

    dp = opendir(CODE_FOLDER_PATH);
    if(dp == NULL) perror("Couldn't open the directory");
    
    int totalFileNo = 0;
    while(ep = readdir(dp)) totalFileNo++;

    char **files = malloc(totalFileNo*sizeof(char *));

    (void) closedir(dp);
    dp = opendir(CODE_FOLDER_PATH);
    
    int totalFileNamesSize = 0;
    int i = 0;
    while(ep = readdir(dp)) {
        char *filename = ep->d_name;
        int len = strlen(filename);
        int isCFile = filename[len-2] == '.' && filename[len-1] == 'c';
        int isMain =    filename[0] == 'm' && 
                        filename[1] == 'a' &&
                        filename[2] == 'i' &&
                        filename[3] == 'n' &&
                        filename[4] == '.' &&
                        filename[5] == 'c' &&
                        filename[6] == '\0';
        if(isCFile && !isMain) {
            files[i] = malloc((strlen(filename)+1)*sizeof(char));
            strcpy(files[i], filename);
            i++;
            totalFileNamesSize += strlen(filename);
        }
    }

    (void) closedir(dp);

    *put = files;
    *totalFileNameSizePtr = totalFileNamesSize;
    *count = i;
}

int main() {
    char **files;
    int count;
    int totalFileNamesSize;
    getFiles(&files, &count, &totalFileNamesSize);
    build(files, count, totalFileNamesSize);

    return 0;
}