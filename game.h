#ifndef GAME_H
#define GAME_H

#define SIZE 10
#define SHIPS 5

typedef struct
{
    char name[50];
    char board[SIZE][SIZE];
    int shipsLeft;
} Player;

void initPlayer(Player *p, const char *name);
void placeShips(Player *p);
void printBoard(Player *p);
int attack(Player *attacker, Player *defender, int row, int col);

#endif
            