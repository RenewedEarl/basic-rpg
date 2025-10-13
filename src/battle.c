#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/characters.h"
#include "../include/textfuncs.h"

int battleMenuCounter;
int tutorialState;
int damage;
char battleInput[100];
int battleChoice = 0;

int getRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void healParty(Character hero)
{
    hero.health = hero.maxHealth;
}

void singleEnemyHealthReset(Monster enemy)
{
    enemy.health = enemy.maxhealth;
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
            damage = getRandom(hero.attack * .50, hero.attack);
            damage -= enemy.defense * .25;
            if(damage < 0)
            {
                damage = 0;
            }
            printf("%s physically attacked %s for %d damage!\n", hero.name, enemy.name, damage);
            enemy.health -= damage;
            waitForEnter();
            clearScreen();
            if(enemy.health <= 0)
            {
                printf("%s had died, you gained %d experience points!\n", enemy.name, enemy.expYield);
                waitForEnter();
                clearScreen();
                healParty(hero);
                singleEnemyHealthReset(enemy);
                if(tutorialState != 1)
                {
                    tutorialState = 1;
                }
                battleMenuCounter = 1;
                break;
            }
            else
            {
                if(enemy.offenseType == 1)
                {
                    damage = getRandom(enemy.attack * .50, enemy.attack);
                    damage -= hero.defense * .25;
                    if(damage < 0)
                    {
                        damage = 0;
                    }
                    printf("%s physically attacked you for %d damage!\n", enemy.name, damage);
                    hero.health -= damage;
                    waitForEnter();
                    clearScreen();
                }
                else if(enemy.offenseType == 2)
                {
                    damage = getRandom(enemy.magic * .50, enemy.magic);
                    damage -= hero.magicDefense * 25;
                    if(damage < 0)
                    {
                        damage = 0;
                    }
                    printf("%s magically attacked you for %d damage!\n", enemy.name, damage);
                    hero.health -= damage;
                    waitForEnter();
                    clearScreen();
                }
                else if(enemy.offenseType == 3)
                {
                    if(getRandom(0, 1) == 1)
                    {
                        damage = getRandom(enemy.attack * .50, enemy.attack);
                        damage -= hero.defense * .25;
                        if(damage < 0)
                        {
                            damage = 0;
                        }
                        printf("%s physically attacked you for %d damage!\n", enemy.name, damage);
                        hero.health -= damage;
                        waitForEnter();
                        clearScreen();
                    }
                    else
                    {
                        damage = getRandom(enemy.magic * .50, enemy.magic);
                        damage -= hero.magicDefense * 25;
                        if(damage < 0)
                        {
                            damage = 0;
                        }
                        printf("%s magically attacked you for %d damage!\n", enemy.name, damage);
                        hero.health -= damage;
                        waitForEnter();
                        clearScreen();
                    }
                }
                
                if(hero.health <= 0)
                {
                    if(tutorialState != 1)
                    {
                        printf("This was just a tutorial so you live, but you will die any other time.\n");
                        tutorialState = 1;
                        healParty(hero);
                        singleEnemyHealthReset(enemy);
                        return;
                    }
                    else
                    {
                        printf("%s has died! Try again in another life.\n", player.name);
                        exit(0);
                    }
                }
                printHealthInSingleBattles(hero, enemy);
                break;
            }
        case 2:
            clearScreen();
            damage = getRandom(hero.magic * .50, hero.magic);
            damage -= enemy.magicDefense * .25;
            if(damage < 0)
            {
                damage = 0;
            }
            printf("%s magically attacked %s for %d damage!\n", hero.name, enemy.name, damage);
            enemy.health -= damage;
            waitForEnter();
            clearScreen();
            if(enemy.health <= 0)
            {
                printf("%s had died, you gained %d experience points!\n", enemy.name, enemy.expYield);
                waitForEnter();
                clearScreen();
                healParty(hero);
                singleEnemyHealthReset(enemy);
                if(tutorialState != 1)
                {
                    tutorialState = 1;
                }
                battleMenuCounter = 1;
                break;
            }
            else
            {
                if(enemy.offenseType == 1)
                {
                    damage = getRandom(enemy.attack * .50, enemy.attack);
                    damage -= hero.defense * .25;
                    if(damage < 0)
                    {
                        damage = 0;
                    }
                    printf("%s physically attacked you for %d damage!\n", enemy.name, damage);
                    hero.health -= damage;
                    waitForEnter();
                    clearScreen();
                }
                else if(enemy.offenseType == 2)
                {
                    damage = getRandom(enemy.magic * .50, enemy.magic);
                    damage -= hero.magicDefense * .25;
                    if(damage < 0)
                    {
                        damage = 0;
                    }
                    printf("%s magically attacked you for %d damage!\n", enemy.name, damage);
                    hero.health -= damage;
                    waitForEnter();
                    clearScreen();
                }
                else if(enemy.offenseType == 3)
                {
                    if(getRandom(0, 1) == 1)
                    {
                        damage = getRandom(enemy.attack * .50, enemy.attack);
                        damage -= hero.defense * .25;
                        if(damage < 0)
                        {
                            damage = 0;
                        }
                        printf("%s physically attacked you for %d damage!\n", enemy.name, damage);
                        hero.health -= damage;
                        waitForEnter();
                        clearScreen();
                    }
                    else
                    {
                        damage = getRandom(enemy.magic * .50, enemy.magic);
                        damage -= hero.magicDefense * .25;
                        if(damage < 0)
                        {
                            damage = 0;
                        }
                        printf("%s magically attacked you for %d damage!\n", enemy.name, damage);
                        hero.health -= damage;
                        waitForEnter();
                        clearScreen();
                    }
                }
                
                if(hero.health <= 0)
                {
                    if(tutorialState != 1)
                    {
                        printf("This was just a tutorial so you live, but you will die any other time.\n");
                        tutorialState = 1;
                        healParty(hero);
                        singleEnemyHealthReset(enemy);
                        return;
                    }
                    else
                    {
                        printf("%s has died! Try again in another life.\n", player.name);
                        exit(0);
                    }
                }
                printHealthInSingleBattles(hero, enemy);
                break;
            }
        case 3:
            clearScreen();
            printf("%s put up his defenses. You now take 50%% less damage!", hero.name);
            waitForEnter();
            clearScreen();
            if(enemy.offenseType == 1)
            {
                damage = getRandom(enemy.attack * .50, enemy.attack);
                damage -= hero.defense * .75;
                if(damage < 0)
                {
                    damage = 0;
                }
                printf("%s physically attacked you for %d damage!\n", enemy.name, damage);
                hero.health -= damage;
                waitForEnter();
                clearScreen();
            }
            else if(enemy.offenseType == 2)
            {
                damage = getRandom(enemy.magic * .50, enemy.magic);
                damage -= hero.magicDefense * 75;
                if(damage < 0)
                {
                    damage = 0;
                }
                printf("%s magically attacked you for %d damage!\n", enemy.name, damage);
                hero.health -= damage;
                waitForEnter();
                clearScreen();
            }
            else if(enemy.offenseType == 3)
            {
                if(getRandom(0, 1) == 1)
                {
                    damage = getRandom(enemy.attack * .50, enemy.attack);
                    damage -= hero.defense * .75;
                    if(damage < 0)
                    {
                        damage = 0;
                    }
                    printf("%s physically attacked you for %d damage!\n", enemy.name, damage);
                    hero.health -= damage;
                    waitForEnter();
                    clearScreen();
                }
                else
                {
                    damage = getRandom(enemy.magic * .50, enemy.magic);
                    damage -= hero.magicDefense * 75;
                    if(damage < 0)
                    {
                        damage = 0;
                    }
                    printf("%s magically attacked you for %d damage!\n", enemy.name, damage);
                    hero.health -= damage;
                    waitForEnter();
                    clearScreen();
                }
            }
            
            if(hero.health <= 0)
            {
                if(tutorialState != 1)
                {
                    printf("This was just a tutorial so you live, but you will die any other time.\n");
                    tutorialState = 1;
                    healParty(hero);
                    singleEnemyHealthReset(enemy);
                    return;
                }
                else
                {
                    printf("%s has died! Try again in another life.\n", player.name);
                    exit(0);
                }
            }
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
    return;
}
