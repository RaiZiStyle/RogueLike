#include "../header/game.h"

int handleInput(int input, Player *user) {
    switch (input) {
        // Move up
        case 'z':
        case 'Z':
            playerMove(user->yPosition - 1, user->xPosition, user);
            /* code */
            break;
        // Move Down
        case 's':
        case 'S':
            playerMove(user->yPosition + 1 , user->xPosition, user);
            /* code */
            break;
        // Move left
        case 'q':
        case 'Q':
            playerMove(user->yPosition, user->xPosition- 1 , user);
            /* code */
            break;
        // Move right
        case 'd':
        case 'D':
            playerMove(user->yPosition , user->xPosition + 1, user);
            /* code */
            break;

        default:
            break;
    }
}