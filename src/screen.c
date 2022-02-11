#include "../header/screen.h"

int screenSetup() {
    initscr();  // Initialise la structure WINDOW et autres paramètres
    printw("Hello world");  // Écrit Hello World à l'endroit où le curseur
                            // logique est positionné
    noecho();               // Disable tty input user
    refresh();

    return 1;
}

