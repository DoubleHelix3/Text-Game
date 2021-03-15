#include "types.h"

typedef struct {
    char *name;
    int dmg;
    Type type;
} Attack;

#define NULL_ATTACK (Attack){"", 0, 0}

Attack getAttack(char *name);
