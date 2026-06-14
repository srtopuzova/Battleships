#include <stdio.h>
#include "replay.h"

void logMove(const char *player, int row, int col, int hit)
{
    FILE *f = fopen("replay.txt", "a");

    if(f == NULL)
        return;

    fprintf(f, "%s %d %d %d\n",
            player,
            row,
            col,
            hit);

    fclose(f);
}

void replayGame()
{
    FILE *f = fopen("replay.txt", "r");

    if(f == NULL)
    {
        printf("No replay available.\n");
        return;
    }

    char player[50];
    int row, col, hit;

    while(fscanf(f,
                 "%49s %d %d %d",
                 player,
                 &row,
                 &col,
                 &hit) == 4)
    {
        printf("%s attacked (%d,%d) -> %s\n",
               player,
               row,
               col,
               hit ? "HIT" : "MISS");
    }

    fclose(f);
}