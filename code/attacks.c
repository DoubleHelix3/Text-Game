#include <string.h>

#include "attacks.h"

const int attacksCount = 2;
const Attack attacks[] = {
    {"dragon's breath", 15, TYPE_FIRE}, 
    {"dragon's blade", 10, TYPE_WATER}, 
};

Attack getAttack(char *name) {
    for(int i=0; i<2; i++) {
        Attack attack = attacks[i];
        if(strcmp(attack.name, name)) return attack;
    }
    return NULL_ATTACK;
}