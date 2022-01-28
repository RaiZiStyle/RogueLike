#include "../header/game.h"

int handleInput(int input, Player *user) {
    int newY;
    int newX;
    switch (input) {
        // Move up
        case 'z':
        case 'Z':
            newY = user->yPosition - 1;
            newX= user->xPosition;
            // playerMove(user->yPosition - 1, user->xPosition, user);
            /* code */
            break;
        // Move Down
        case 's':
        case 'S':
            newY = user->yPosition + 1;
            newX = user->xPosition;
            // playerMove(user->yPosition + 1 , user->xPosition, user);
            /* code */
            break;
        // Move left
        case 'q':
        case 'Q':
            newY = user->yPosition;
            newX = user->xPosition - 1;
            // playerMove(user->yPosition, user->xPosition- 1 , user);
            /* code */
            break;
        // Move right
        case 'd':
        case 'D':
            newY = user->yPosition;
            newX = user->xPosition + 1;
            // playerMove(user->yPosition , user->xPosition + 1, user);
            /* code */
            break;

        default:
            break;
    }

    checkPosition(newY, newX, user);
}

/* Check what is a next position */
int checkPosition(int newY, int newX, Player *unit) {
    int space;
    // mvinch will return a char of the current position of cursor
    switch (mvinch(newY, newX)) {
        case '.':
            playerMove(newY, newX, unit);
            break;

        default:
            move(unit->yPosition, unit->xPosition);
            break;
    }
}