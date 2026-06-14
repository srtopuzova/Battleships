#include <stdio.h>
#include <stdlib.h>
#include "singleplayer.h"

void placeShipsRandom(Player *p){
    int shipsPlaced = 0;

    while(shipsPlaced < SHIPS){
        int r = rand() % SIZE;
        int c = rand() % SIZE;

        if(p->board[r][c] == '.'){
            p->board[r][c] = 'S';
            shipsPlaced++;
        }
    }
}

void printHiddenBoard(Player *p){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
        if(p->board[i][j] == 'S')
            printf(". ");
        else
            printf("%c ", p->board[i][j]);
        }   
        printf("\n");
    }
}

void singlePlayerGame(){
    Player player;
    Player computer;

    initPlayer(&player, "Player");
    initPlayer(&computer, "Computer");

    placeShips(&player);
    placeShipsRandom(&computer);

    int computerShots[SIZE][SIZE] = {0};

    while(player.shipsLeft > 0 && computer.shipsLeft > 0){
        int row, col;

        printf("\n====================\n");
        printf("YOUR BOARD\n");
        printBoard(&player);

        printf("\nENEMY BOARD\n");
        printHiddenBoard(&computer);

        printf("\nAttack (row col): ");
        scanf("%d %d", &row, &col);

        if(row < 0 || row >= SIZE || col < 0 || col >= SIZE){
            printf("Invalid coordinates!\n");
            continue;
        }

        if(attack(&player, &computer, row, col))
            printf("Hit!\n");
        else
            printf("Miss!\n");

        if(computer.shipsLeft == 0)
            break;

        int aiRow;
        int aiCol;

        do{
            aiRow = rand() % SIZE;
            aiCol = rand() % SIZE;
        }while(computerShots[aiRow][aiCol]);

        computerShots[aiRow][aiCol] = 1;

        printf("\nComputer attacks (%d %d)\n", aiRow, aiCol);

        if(attack(&computer, &player, aiRow, aiCol)){
            printf("Computer hit!\n");
        }
        else{
            printf("Computer missed!\n");
        }
    }

    printf("\n====================\n");

    if(player.shipsLeft > 0)
        printf("YOU WIN!\n");
    else
        printf("COMPUTER WINS!\n");
}