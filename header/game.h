#ifndef GAME_H
#define GAME_H
#include "../header/player.h"
#include "../header/screen.h"

typedef struct Position{
    int x;
    int y;
    // TILE_TYPE tile;
}Position;

typedef struct Room{
    Position position;
    int height;
    int width;
    // Monster **monster;
    // Item **item;
}Room;

int handleInput(int input, Player *user);
int checkPosition(int newY, int newX, Player *unit);
#endif