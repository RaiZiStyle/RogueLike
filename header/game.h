#ifndef GAME_H
#define GAME_H

#include "../header/player.h"


int handleInput(int input, Player *user);
int checkPosition(int newY, int newX, Player *unit);
#endif