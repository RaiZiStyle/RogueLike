#include "../header/player.h"

Player *playerSetup() {
    Player *newPlayer;
    newPlayer = malloc(sizeof(Player));
    newPlayer->position.x = 14;
    newPlayer->position.y = 14;
    newPlayer->health = 20;

    // mvprintw(newPlayer->yPosition, newPlayer->xPosition, "@");
    // move(newPlayer->yPosition, newPlayer->xPosition);

    //playerMove(14,14, newPlayer);
    mvprintw(newPlayer->position.y,newPlayer->position.x, "@");
    move(newPlayer->position.y,newPlayer->position.x);

    return newPlayer;
}

int playerMove(Position *newPosition, Player *user, char **level) {
    char buffer[8];
    
    sprintf(buffer,"%c", level[user->position.y][user->position.x]);
    mvprintw(user->position.y, user->position.x, buffer);
    user->position.y= newPosition->y;
    user->position.x = newPosition->x;
    // printf("user->position.x : %d, user->position.y: %d, x : %d, y : %d\n", user->position.x, user->position.y, x, y);

    mvprintw(user->position.y, user->position.x, "@");
    move(user->position.y, user->position.x);


    return 1;
}