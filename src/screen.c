#include "../header/screen.h"

int screenSetup() {
    initscr();  // Initialise la structure WINDOW et autres paramètres
    printw("Hello world");  // Écrit Hello World à l'endroit où le curseur
                            // logique est positionné
    noecho();               // Disable tty input user
    refresh();

    return 1;
}

int mapSetup() {
    mvprintw(13, 13, "------------");
    mvprintw(14, 13, "|..........|");
    mvprintw(15, 13, "|..........|");
    mvprintw(16, 13, "|..........|");
    mvprintw(17, 13, "|..........|");
    mvprintw(18, 13, "|..........|");
    mvprintw(18, 13, "------------");

    mvprintw(2, 40, "---------");
    mvprintw(3, 40, "|.......|");
    mvprintw(4, 40, "|.......|");
    mvprintw(5, 40, "|.......|");
    mvprintw(6, 40, "|.......|");
    mvprintw(7, 40, "---------");

    mvprintw(10, 40, "------------");
    mvprintw(11, 40, "|..........|");
    mvprintw(12, 40, "|..........|");
    mvprintw(13, 40, "|..........|");
    mvprintw(14, 40, "|..........|");
    mvprintw(15, 40, "-----------");
}