#ifndef CHARACTERS_H
#define CHARACTERS_H

typedef struct Character
{
    char name[100];
    char job[100];
    int health;
    int attack;
    int magic;
    int defense;
    int magicDefense;
    int speed;
} Character;

#endif
