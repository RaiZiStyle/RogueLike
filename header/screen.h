#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include "../header/game.h"
int screenSetup();
Room **mapSetup();
Room *createRoom(int x, int y, int height, int width);
int drawRoom(Room *room);
#endif