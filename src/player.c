#include "../header/player.h"

Player *playerSetup() {
    Player *newPlayer;
    newPlayer = malloc(sizeof(Player));
    newPlayer->position.x = 14;
    newPlayer->position.y = 14;
    newPlayer->health = 20;

    // mvprintw(newPlayer->yPosition, newPlayer->xPosition, "@");
    // move(newPlayer->yPosition, newPlayer->xPosition);

    playerMove(14,14, newPlayer);

    return newPlayer;
}

int playerMove(int y, int x, Player *user) {
    mvprintw(user->position.y, user->position.y, ".");
    user->position.y= y;
    user->position.x = x;

    mvprintw(user->position.y, user->position.x, "@");
    move(user->position.y, user->position.x);
}