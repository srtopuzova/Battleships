#include <stdio.h>
#include "game.h"
#include "singleplayer.h"
#include "replay.h"
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include <stdint.h>

#define DEBUG_MODE 0

int main()
{
    int choice;
    uint32_t key = randomUI32T();

    srand(time(NULL));

    printf("1. Multiplayer\n");
    printf("2. Singleplayer\n");
    printf("3. Replay\n");
    scanf("%d", &choice);

    if(choice == 2)
    {
        singlePlayerGame();
        return 0;
    }

    if(choice == 3)
    {
        replayGame(key);
        return 0;
    }

    FILE *f = fopen("replay.txt", "w");
    if(f)
    {
#if DEBUG_MODE
        fprintf(f, "Decryption key: %u\n", key);
#endif
        fclose(f);
    }

    Player p1, p2;

    initPlayer(&p1, "Player1");
    initPlayer(&p2, "Player2");

    placeShips(&p1);
    placeShips(&p2);

    while(p1.shipsLeft > 0 && p2.shipsLeft > 0)
    {
        int r, c;
        int hit;

        printf("\n%s turn: ", p1.name);
        scanf("%d %d", &r, &c);

        hit = attack(&p1, &p2, r, c);

        logMove(p1.name, r, c, hit, key);

        if(hit)
            printf("Hit!\n");
        else
            printf("Miss!\n");

        if(p2.shipsLeft == 0)
            break;

        printf("\n%s turn: ", p2.name);
        scanf("%d %d", &r, &c);

        hit = attack(&p2, &p1, r, c);

        logMove(p2.name, r, c, hit, key);

        if(hit)
            printf("Hit!\n");
        else
            printf("Miss!\n");
    }

    printf("\nWinner: %s\n", p1.shipsLeft ? p1.name : p2.name);

    return 0;
}