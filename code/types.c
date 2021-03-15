#include "types.h"

// typeAdvantages[attack][gettingAttacked]
const float typeAdvantages[TYPE_COUNT][TYPE_COUNT] = {
//  norm, water, earth, fire
    {1.0f, 1.0f, 1.0f, 1.0f},
    {1.5f, 1.0f, 0.5f, 3.0f},
    {1.0f, 1.5f, 0.5f, 2.0f},
    {3.0f, 1.0f, 0.5f, 1.0f},
};

float calculateTypeAdvantage(Type attack, Type gettingAttacked) {
    return typeAdvantages[attack][gettingAttacked];
}