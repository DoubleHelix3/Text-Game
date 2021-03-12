#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 25

int main() {
    printf("Greetings traveler!\n");
    printf("What is your name?\n-");
    char name[MAX_NAME_LENGTH];
    fgets(name, MAX_NAME_LENGTH, stdin);
    // get rid of that new line character at the end
    name[strcspn(name, "\n")] = 0;
    printf("%s is a nice name!\n", name);
    return 0;
}