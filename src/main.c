#include "../header/screen.h"
#include "../header/player.h"
#include "../header/game.h"


int main(){
    // Initialisation 
    Player *user;
    int ch;

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