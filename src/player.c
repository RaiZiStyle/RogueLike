#include "../header/player.h"

Player *playerSetup() {
    Player *newPlayer;
    newPlayer = malloc(sizeof(Player));
    newPlayer->xPosition = 14;
    newPlayer->yPosition = 14;
    newPlayer->health = 20;

    mvprintw(newPlayer->yPosition, newPlayer->xPosition, "@");
    move(newPlayer->yPosition, newPlayer->xPosition);

    return newPlayer;
}