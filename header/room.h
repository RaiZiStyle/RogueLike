#ifndef ROOM_H
#define ROOM_H

#include <stdio.h>  
#include <stdlib.h> // Malloc
#include <ncurses.h>
#include <time.h>
#include "../header/position.h"

typedef struct _Room{
    Position position;
    Position **doors;
    int height;
    int width;
    // Monster **monster;
    // Item **item;
}Room;


Room **mapSetup();
Room *createRoom(int x, int y, int height, int width);
int drawRoom(Room *room);
int connectDoors(Position *doorOne, Position *doorTwo);
char **saveLevelPosition();

#endif