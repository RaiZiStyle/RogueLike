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
    mvprintw(user->position.y, user->position.x, ".");
    user->position.y= y;
    user->position.x = x;
    // printf("user->position.x : %d, user->position.y: %d, x : %d, y : %d\n", user->position.x, user->position.y, x, y);

    mvprintw(user->position.y, user->position.x, "@");
    move(user->position.y, user->position.x);


    return 1;
}