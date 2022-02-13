#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <ncurses.h>
// #include "../header/game.h"
#include "../header/position.h"




typedef struct _Player{
    Position position;
    int health;
    // Room *room;
} Player;


Player *playerSetup();
int playerMove(int y, int x, Player *user);


#endif