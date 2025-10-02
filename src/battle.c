#include <stdio.h>
#include "../include/characters.h"
#include "../include/textfuncs.h"

int battleMenuCounter;
char battleInput[100];
int battleChoice = 0;

void initSingleBattle(Character hero, Monster enemy)
{
    battleMenuCounter = 0;
    printf("%s has run into a %s, it's time to fight!\n", hero.name, enemy.name);
    waitForEnter();
    clearScreen();
    printf("--- %s / %d HP ---\n", player.name, player.health);
    printf("--- %s / %d HP ---\n", enemy.name, enemy.health);
    while(battleMenuCounter == 0)
    {
        printf("\n");
        printf("-- Battle Commands --\n");
        printf("1. Fight\n");
        printf("2. Magic\n");
        printf("3. Defend\n");
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
                printf("--- %s / %d HP ---\n", player.name, player.health);
                printf("--- %s / %d HP ---\n", enemy.name, enemy.health);
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
                printf("--- %s / %d HP ---\n", player.name, player.health);
                printf("--- %s / %d HP ---\n", enemy.name, enemy.health);
                break;
            }
        case 3:
            clearScreen();
            printf("%s put up his defenses. You now take 50%% less damage!", player.name);
            waitForEnter();
            clearScreen();
            printf("Enemy battles you... (behavior will come later).\n");
            waitForEnter();
            clearScreen();
            printf("--- %s / %d HP ---\n", player.name, player.health);
            printf("--- %s / %d HP ---\n", enemy.name, enemy.health);
            break;
        }
    }
}
