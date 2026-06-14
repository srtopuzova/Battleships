#include <stdio.h>
#include <string.h>
#include "game.h"

void initPlayer(Player *p, const char *name)
{
    strcpy(p->name, name);
        p->shipsLeft = SHIPS;

            for(int i=0;i<SIZE;i++)
                    for(int j=0;j<SIZE;j++)
                                p->board[i][j]='.';
                                }

                                void placeShips(Player *p)
                                {
                                    int r,c;

                                        printf("\n%s place %d ships\n", p->name, SHIPS);

                                            for(int i=0;i<SHIPS;i++)
                                                {
                                                        printf("Ship %d (row col): ",i+1);
                                                                scanf("%d %d",&r,&c);

                                                                        if(r<0 || r>=SIZE || c<0 || c>=SIZE || p->board[r][c]=='S')
                                                                                {
                                                                                            i--;
                                                                                                        continue;
                                                                                                                }

                                                                                                                        p->board[r][c]='S';
                                                                                                                            }
                                                                                                                            }

                                                                                                                            void printBoard(Player *p)
                                                                                                                            {
                                                                                                                                for(int i=0;i<SIZE;i++)
                                                                                                                                    {
                                                                                                                                            for(int j=0;j<SIZE;j++)
                                                                                                                                                        printf("%c ",p->board[i][j]);

                                                                                                                                                                printf("\n");
                                                                                                                                                                    }
                                                                                                                                                                    }

                                                                                                                                                                    int attack(Player *attacker, Player *defender, int row, int col)
                                                                                                                                                                    {
                                                                                                                                                                        (void)attacker;

                                                                                                                                                                            if(defender->board[row][col]=='S')
                                                                                                                                                                                {
                                                                                                                                                                                        defender->board[row][col]='X';
                                                                                                                                                                                                defender->shipsLeft--;
                                                                                                                                                                                                        return 1;
                                                                                                                                                                                                            }

                                                                                                                                                                                                                return 0;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                