#include "../include/characters.h"

Character player = 
{
    .name = "Default",
    .job = "Freelancer",
    .health = 0,
    .maxHealth = 0,
    .attack = 0,
    .magic = 0,
    .defense = 0,
    .magicDefense = 0,
    .speed = 0
};

Monster goblin = 
{
    .name = "Goblin",
    .expYield = 75,
    .health = 20,
    .maxhealth = 20,
    .attack = 8,
    .magic = 0,
    .defense = 3,
    .magicDefense = 3,
    .speed = 3,
    .offenseType = 1
};
