#include <stdio.h>
#include <string.h>

void getStringInput(char *string, int maxLength)
{
    if(fgets(string, maxLength, stdin))
    {
        // Remove newline character if present
        size_t index = 0;
        while(string[index] != '\0')
        {
            if(string[index] == '\n')
            {
                string[index] = '\0';
                break;
            }
            index++;
        }
    }
}

void getMenuInput(char *option, int *choice)
{
    // Read string input
    if (fgets(option, 100, stdin)) 
    {
        // Remove newline character
        size_t len = strlen(option);
        if (len > 0 && option[len - 1] == '\n') 
        {
            option[len - 1] = '\0';
        }

        // Convert string to integer
        if (sscanf(option, "%d", choice) != 1) 
        {
            *choice = -1; // Indicate invalid input
        }
    } 
    else 
    {
        *choice = -1;
    }
}

void printStatSheet(char *name, char *job, int hp, int atk, int def, int mag, int mgdef, int spe)
{
    printf("Name: %s\n", name);
    printf("Class: %s\n", job);
    printf("Health: %d\n", hp);
    printf("Attack: %d\n", atk);
    printf("Defense: %d\n", def);
    printf("Magic: %d\n", mag);
    printf("Magic Defense: %d\n", mgdef);
    printf("Speed: %d\n", spe);
}
