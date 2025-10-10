#ifndef ADVENTUREAREA_H
#define ADVENTUREAREA_H

typedef struct Area
{
    int areaIdentifier;
}Area;

extern Area controller;

void areaControl();
void startingArea();

#endif
