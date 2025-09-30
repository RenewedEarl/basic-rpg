#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/characters.h"
#include "../include/textfuncs.h"
#include "../include/adventurearea.h"
#include "../include/mainmenu.h"

int menuState = 0;
char input[100];
int choice = 0;
int inputState;
Character player;

void printMainMenus()
{
    while(1)
    {
        if(menuState == 0)
        {
            printf("\n--- Basic RPG ---\n");
            printf("1. New Game\n");
            printf("2. Quit\n");
            printf("\nPlease choose an option: ");
            getMenuInput(input, &choice);

            switch(choice)
            {
            case 1:
                newGameSequence();
                printf("Now that that's out of the way, please enjoy the adventure!\n");
                menuState = 1;
                mainAdventureArea();
            case 2:
                printf("Thanks for playing!\n");
                exit(0);
            default:
                printf("Please give a proper answer.\n");
                break;
            }
        }
        else if(menuState == 1)
        {
            printf("\n--- Basic RPG ---\n");
            printf("1. New Game\n");
            printf("2. Continue Game\n");
            printf("3. Stat Sheet\n");
            printf("4. Quit\n");
            printf("\nPlease choose an option: ");
            getMenuInput(input, &choice);

            switch(choice)
            {
            case 1:
                newGameSequence();
                printf("Now that that's out of the way, please enjoy the adventure!\n");
                mainAdventureArea();
            case 2:
            case 3:
                printStatSheet(player.name, player.job, player.health, player.attack, player.defense, player.magic, player.magicDefense, player.speed);
                break;
            case 4:
            }
        }
    }
}

void newGameSequence()
{
    inputState = 0;
    printf("Ok, it's time to set up your character!\n");
    printf("What is your character's name?: ");
    getStringInput(player.name, sizeof(player.name));
    printf("There a four classes to choose from: Warrior, Mage, Healer, and Rogue.\n");
    while(inputState == 0)
    {
        printf("Which one do you want to be?: ");
        getStringInput(player.job, sizeof(player.job));
        if(strcmp(player.job, "Warrior") == 0)
        {
            player.health = 10;
            player.attack = 10;
            player.magic = 0;
            player.defense = 8;
            player.magicDefense = 6;
            player.speed = 5;
            printf("You have chosen the Warrior class. Here is your stat sheet before you begin:\n");
            printStatSheet(player.name, player.job, player.health, player.attack, player.defense, player.magic, player.magicDefense, player.speed);
            inputState = 1;
        }
        else if(strcmp(player.job, "Mage") == 0)
        {
            player.health = 8;
            player.attack = 5;
            player.magic = 10;
            player.defense = 5;
            player.magicDefense = 8;
            player.speed = 7;
            printf("You have chosen the Mage class. Here is your stat sheet before you begin:\n");
            printStatSheet(player.name, player.job, player.health, player.attack, player.defense, player.magic, player.magicDefense, player.speed);
            inputState = 1;
        }
        else if(strcmp(player.job, "Healer") == 0)
        {
            player.health = 10;
            player.attack = 3;
            player.magic = 10;
            player.defense = 7;
            player.magicDefense = 7;
            player.speed = 6;
            printf("You have chosen the Healer class. Here is your stat sheet before you begin:\n");
            printStatSheet(player.name, player.job, player.health, player.attack, player.defense, player.magic, player.magicDefense, player.speed);
            inputState = 1;
        }
        else if(strcmp(player.job, "Rogue") == 0)
        {
            player.health = 5;
            player.attack = 9;
            player.magic = 7;
            player.defense = 5;
            player.magicDefense = 6;
            player.speed = 10;
            printf("You have chosen the Rogue class. Here is your stat sheet before you begin:\n");
            printStatSheet(player.name, player.job, player.health, player.attack, player.defense, player.magic, player.magicDefense, player.speed);
            inputState = 1;
        }
        else
        {
            printf("Please give a proper answer.\n");
        }
    }
}
