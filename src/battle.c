#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/characters.h"
#include "../include/textfuncs.h"

int battleMenuCounter;
int tutorialState;
char battleInput[100];
int battleChoice = 0;

int getRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void initSingleBattle(Character hero, Monster enemy)
{
    battleMenuCounter = 0;
    printf("%s has run into a %s, it's time to fight!\n", hero.name, enemy.name);
    waitForEnter();
    clearScreen();
    printHealthInSingleBattles(hero, enemy);
    while(battleMenuCounter == 0)
    {
        printf("\n");
        printf("-- Battle Commands --\n");
        printf("1. Fight\n");
        printf("2. Magic\n");
        printf("3. Defend\n");
        printf("4. Run\n");
        printf("\nPlease choose an option: ");
        getMenuInput(battleInput, &battleChoice);

        switch(battleChoice)
        {
        case 1:
            clearScreen();
            printf("%s physically attacked %s for (n/a) damage!\n", hero.name, enemy.name);
            waitForEnter();
            clearScreen();
            if(enemy.health <= 0)
            {
                printf("%s had died, you gained (n/a) experience points!\n", enemy.name);
                waitForEnter();
                clearScreen();
                battleMenuCounter = 1;
                break;
            }
            else
            {
                printf("Enemy battles you... (behavior will come later).\n");
                waitForEnter();
                clearScreen();
                printHealthInSingleBattles(hero, enemy);
                break;
            }
        case 2:
            clearScreen();
            printf("%s magically attacked %s for (n/a) damage!\n", hero.name, enemy.name);
            waitForEnter();
            clearScreen();
            if(enemy.health <= 0)
            {
                printf("%s had died, you gained (n/a) experience points!\n", enemy.name);
                waitForEnter();
                clearScreen();
                battleMenuCounter = 1;
                break;
            }
            else
            {
                printf("Enemy battles you... (behavior will come later).\n");
                waitForEnter();
                clearScreen();
                printHealthInSingleBattles(hero, enemy);
                break;
            }
        case 3:
            clearScreen();
            printf("%s put up his defenses. You now take 50%% less damage!", hero.name);
            waitForEnter();
            clearScreen();
            printf("Enemy battles you... (behavior will come later).\n");
            waitForEnter();
            clearScreen();
            printHealthInSingleBattles(hero, enemy);
            break;
        case 4:
            if(tutorialState != 1)
            {
                clearScreen();
                printf("You can't run from this battle.\n");
                waitForEnter();
                clearScreen();
                printHealthInSingleBattles(hero, enemy);
                break;
            }
            else
            {
                clearScreen();
                if(hero.speed >= enemy.speed)
                {
                    if(getRandom(0, 1) == 1)
                    {
                        printf("You've ran successfully!\n");
                        waitForEnter();
                        clearScreen();
                        battleMenuCounter = 1;
                        break;
                    }
                    else
                    {
                        printf("You couldn't get away...\n");
                        waitForEnter();
                        clearScreen();
                        printHealthInSingleBattles(hero, enemy);
                        break;
                    }
                }
                else
                {
                    printf("Your speed is too slow to try.\n");
                    waitForEnter();
                    clearScreen();
                    printHealthInSingleBattles(hero, enemy);
                    break;    
                }
            }
        default:
            clearScreen();
            printf("Please give proper input.\n");
            waitForEnter();
            clearScreen();
            printHealthInSingleBattles(hero, enemy);
            break;
        }
    }
}
