#include <stdio.h>
#include "../include/textfuncs.h"
#include "../include/mainmenu.h"
#include "../include/characters.h"
#include "../include/battle.h"

void mainAdventureArea()
{
    printf("Welcome to the world of Earthengarde, %s!\n", player.name);
    printf("Let's get you acquainted with how to battle before you go off on your adventure.\n");
    waitForEnter();
    initSingleBattle(player, goblin);
}
