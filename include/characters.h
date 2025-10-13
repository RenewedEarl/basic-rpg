#ifndef CHARACTERS_H
#define CHARACTERS_H

// Types of Characters
typedef struct Character
{
    char name[100];
    char job[100];
    int health;
    int maxHealth;
    int attack;
    int magic;
    int defense;
    int magicDefense;
    int speed;
} Character;

typedef struct Monster
{
    char name[100];
    int expYield;
    int health;
    int maxhealth;
    int attack;
    int magic;
    int defense;
    int magicDefense;
    int speed;
    int offenseType;
} Monster;

// Character Objects
extern Character player;
extern Monster goblin;

#endif
