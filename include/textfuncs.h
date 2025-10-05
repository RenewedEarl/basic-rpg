#ifndef TEXTFUNCS_H
#define TEXTFUNCS_H

#include "characters.h"

void getStringInput(char *string, int maxLength);
void getMenuInput(char *option, int *choice);
void printStatSheet(char *name, char *job, int hp, int atk, int def, int mag, int mgdef, int spe);
void waitForEnter();
void clearScreen();
void printHealthInSingleBattles(Character mc, Monster foe);

#endif
