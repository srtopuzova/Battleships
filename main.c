#include <stdio.h>
#include "game.h"
#include "singleplayer.h"
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice;
    srand(time(NULL));
    printf("1. Multiplayer\n");
    printf("2. Singleplayer\n");
    scanf("%d", &choice);
    if(choice == 2){
        singlePlayerGame();
        return 0;
    }
    Player p1,p2;

        initPlayer(&p1,"Player1");
            initPlayer(&p2,"Player2");

                placeShips(&p1);
                    placeShips(&p2);

                        while(p1.shipsLeft>0 && p2.shipsLeft>0)
                            {
                                    int r,c;

                                            printf("\n%s turn: ",p1.name);
                                                    scanf("%d %d",&r,&c);

                                                            if(attack(&p1,&p2,r,c))
                                                                        printf("Hit!\n");
                                                                                else
                                                                                            printf("Miss!\n");

                                                                                                    if(p2.shipsLeft==0)
                                                                                                                break;

                                                                                                                        printf("\n%s turn: ",p2.name);
                                                                                                                                scanf("%d %d",&r,&c);

                                                                                                                                        if(attack(&p2,&p1,r,c))
                                                                                                                                                    printf("Hit!\n");
                                                                                                                                                            else
                                                                                                                                                                        printf("Miss!\n");
                                                                                                                                                                            }

                                                                                                                                                                                printf("\nWinner: %s\n",
                                                                                                                                                                                           p1.shipsLeft ? p1.name : p2.name);

                                                                                                                                                                                               return 0;
                                                                                                                                                                                               }
                                                                                                                                                                                               