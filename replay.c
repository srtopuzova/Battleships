#include <stdio.h>
#include "replay.h"
#include "utils.h"
#include <stdint.h>

void logMove(const char *player, int row, int col, int hit, uint32_t key)
{
    FILE *f = fopen("replay.txt", "a");

    if(f == NULL)
        return;

    fprintf(f, "%s %llu\n", player, encryptMove(row, col, hit, key));

    fclose(f);
}

void replayGame(uint32_t key)
{
    FILE *f = fopen("replay.txt", "r");

    if(f == NULL)
    {
        printf("No replay available.\n");
        return;
    }

    char player[50];
    int row, col, hit;
    uint64_t packedMove;

    while(fscanf(f, "%s %llu", player, &packedMove) == 2) {
        decryptMove(packedMove, key, &row, &col, &hit);
        printf("%s attacked (%d, %d) and it was a %s.\n", player, row, col, hit ? "hit" : "miss");
    }

    fclose(f);
}