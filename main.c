#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/mainmenu.h"

int main(void)
{
    // Set RNG Seed
    srand(time(NULL));
    
    // Call Entry Point
    printMainMenus();
}
