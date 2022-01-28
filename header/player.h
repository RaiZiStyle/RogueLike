#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <ncurses.h>



typedef struct Player{
    int xPosition;
    int yPosition;
    int health;
} Player;
Player *playerSetup();
#endif