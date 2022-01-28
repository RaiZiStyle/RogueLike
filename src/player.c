#include "../header/player.h"

Player *playerSetup() {
    Player *newPlayer;
    newPlayer = malloc(sizeof(Player));
    newPlayer->xPosition = 14;
    newPlayer->yPosition = 14;
    newPlayer->health = 20;

    // mvprintw(newPlayer->yPosition, newPlayer->xPosition, "@");
    // move(newPlayer->yPosition, newPlayer->xPosition);

    playerMove(14,14, newPlayer);

    return newPlayer;
}

int playerMove(int y, int x, Player *user) {
    mvprintw(user->yPosition, user->xPosition, ".");
    user->yPosition = y;
    user->xPosition = x;

    mvprintw(user->yPosition, user->xPosition, "@");
    move(user->yPosition, user->xPosition);
}