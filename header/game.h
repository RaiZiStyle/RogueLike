#ifndef GAME_H
#define GAME_H

#include "../header/player.h"


Position *handleInput(int input, Player *user);
int checkPosition(Position *newPosition, Player *unit, char **level);
#endif