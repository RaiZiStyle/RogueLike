#ifndef ROOM_H
#define ROOM_H

#include <stdio.h>  
#include <stdlib.h> // Malloc
#include "../header/position.h"

typedef struct _Room{
    Position position;
    int height;
    int width;
    // Monster **monster;
    // Item **item;
}Room;


Room **mapSetup();
Room *createRoom(int x, int y, int height, int width);
int drawRoom(Room *room);

#endif