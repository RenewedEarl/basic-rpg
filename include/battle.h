#ifndef BATTLE_H
#define BATTLE_H

#include "characters.h"

int getRandom(int min, int max);
void healParty(Character hero);
void initSingleBattle(Character hero, Monster enemy);

#endif
