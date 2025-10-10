#include <stdio.h>
#include "../include/textfuncs.h"
#include "../include/mainmenu.h"
#include "../include/characters.h"
#include "../include/battle.h"
#include "../include/adventurearea.h"

Area controller = 
{
    .areaIdentifier = 0
};

void areaControl()
{
    if(controller.areaIdentifier == 0)
    {
        startingArea();
    }
}

void startingArea()
{
    printf("Welcome to the world of Earthengarde, %s!\n", player.name);
    printf("Let's get you acquainted with how to battle before you go off on your adventure.\n");
    waitForEnter();
    initSingleBattle(player, goblin);
    printf("That's what a basic battle feels like!\n");
    waitForEnter();
    clearScreen();
}
