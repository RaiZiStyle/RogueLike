#ifndef MAIN_C

#include "../header/game.h"
#include "../header/screen.h"
#include "../header/player.h"
#include "../header/room.h"


int main(){
    // Initialisation 
    Player *user;
    int ch;

    srand(time(NULL));
    screenSetup();
    mapSetup();
    user = playerSetup();
    
    // Main game loop
    while ((ch = getch()) != 0x1b){
        handleInput(ch, user);

    }

    endwin();

    return 1;
}

#endif