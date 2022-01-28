#ifndef PLAYER_H

#include <stdlib.h>
#include <ncurses.h>

#endif

typedef struct Player{
    int xPosition;
    int yPosition;
    int health;
} Player;

Player *playerSetup();