#include <stdlib.h>
#include <stdio.h>

#include "ioapi.h"

typedef int Type;
const int NUM_TYPES = 4;
const Type NORMAL = 0; 
const Type WATER = 1;
const Type EARTH = 2;
const Type FIRE = 3;

typedef struct {
    char *name;
    int dmg;
    Type type;
} Attack;

Attack newAttack(char *name, int dmg) {
    Attack attack = {name, dmg};
    return attack;
}

int putAllAttacks(Attack *attacks) {
    int attacksLength = 2;
    attacks = malloc(attacksLength*sizeof(Attack));
    attacks[0] = newAttack("jab", 10);
    attacks[1] = newAttack("side kick", 20);
    return attacksLength;
}

int main() {
    Attack *attacks;
    int attacksLength = putAllAttacks(attacks);

    free(attacks);
    return 0;
}