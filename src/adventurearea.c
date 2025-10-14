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
    else if(controller.areaIdentifier == 1)
    {
        etnaForest();
    }
}

void startingArea()
{
    printf("Welcome to the world of Earthengarde, %s!\n", player.name);
    printf("Let's get you acquainted with how to battle before you go off on your adventure.\n");
    waitForEnter();
    initSingleBattle(player, goblin);
    printf("Now that you've experienced a taste of the trials to come, good luck on your adventure!\n");
    waitForEnter();
    clearScreen();
    controller.areaIdentifier = 1;
    areaControl();
}

void etnaForest()
{
    printf("You've been dropped in the middle of a lush forest, fauna is everywhere and there even\n");
    printf("seems to be giant bugs all over the place!\n");
    waitForEnter();
    clearScreen();
}
