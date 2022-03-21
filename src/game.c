#include "../header/game.h"

Position *handleInput(int input, Player *user) {
    Position *newPosition;

    newPosition = malloc(sizeof(Position));
    if (newPosition == NULL){printf("Error in malloc"); exit(1);}

    switch (input) {
        // Move up
        case 'z':
        case 'Z':
            newPosition->y = user->position.y - 1;
            newPosition->x= user->position.x;
            // playerMove(user->yPosition - 1, user->xPosition, user);
            /* code */
            break;
        // Move Down
        case 's':
        case 'S':
            newPosition->y = user->position.y + 1;
            newPosition->x = user->position.x;
            // playerMove(user->yPosition + 1 , user->xPosition, user);
            /* code */
            break;
        // Move left
        case 'q':
        case 'Q':
            newPosition->y = user->position.y;
            newPosition->x = user->position.x - 1;
            // playerMove(user->yPosition, user->xPosition- 1 , user);
            /* code */
            break;
        // Move right
        case 'd':
        case 'D':
            newPosition->y= user->position.y;
            newPosition->x = user->position.x + 1;
            // playerMove(user->yPosition , user->xPosition + 1, user);
            /* code */
            break;

        default:
            break;
    }

    //checkPosition(newPosition, user);

    return newPosition;
}

/* Check what is a next position */
int checkPosition(Position *newPosition, Player *unit, char **level) {
    //int space;
    // mvinch will return a char of the current position of cursor
    switch (mvinch(newPosition->y, newPosition->x)) {
        case '#':
        case '+':
        case '.':
            playerMove(newPosition, unit, level);
            break;

        default:
            move(unit->position.y, unit->position.x);
            break;
    }
    return 1;
}