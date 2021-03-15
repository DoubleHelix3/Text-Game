#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ioapi.h"

#include "types.h"
#include "attacks.h"

void printAttack(Attack attack) {
    printf("%s, %d, %d\n", attack.name, attack.dmg, attack.type);
}

int main() {
    printAttack(getAttack("dragon's breath"));
    printAttack(getAttack("dragon's blade"));
    return 0;
}