#ifndef MAIN_C

#include "../header/game.h"
#include "../header/screen.h"
#include "../header/player.h"
#include "../header/room.h"


int main(){
    // Initialisation 
    Player *user;
    Position *newPosition;
    char **level;
    int ch;

    srand(time(NULL));
    screenSetup();
    mapSetup();
    level = saveLevelPosition();

    user = playerSetup();
    
    // Main game loop
    while ((ch = getch()) != 0x1b){
        newPosition = handleInput(ch, user);
        checkPosition(newPosition, user, level);

    }

    endwin();

    return 1;
}

#endif