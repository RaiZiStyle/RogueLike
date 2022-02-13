#include "../header/room.h"

Room **mapSetup() {
    Room **rooms;
    rooms = malloc(sizeof(Room) * 6);

    // mvprintw(13, 13, "------------");
    // mvprintw(14, 13, "|..........|");
    // mvprintw(15, 13, "|..........|");
    // mvprintw(16, 13, "|..........|");
    // mvprintw(17, 13, "|..........|");
    // mvprintw(18, 13, "|..........|");
    // mvprintw(18, 13, "------------");
    rooms[0] = createRoom(13, 13, 6, 8);
    drawRoom(rooms[0]);

    // mvprintw(2, 40, "---------");
    // mvprintw(3, 40, "|.......|");
    // mvprintw(4, 40, "|.......|");
    // mvprintw(5, 40, "|.......|");
    // mvprintw(6, 40, "|.......|");
    // mvprintw(7, 40, "---------");
    rooms[1] = createRoom(40, 2, 6, 8);
    drawRoom(rooms[1]);

    // mvprintw(10, 40, "------------");
    // mvprintw(11, 40, "|..........|");
    // mvprintw(12, 40, "|..........|");
    // mvprintw(13, 40, "|..........|");
    // mvprintw(14, 40, "|..........|");
    // mvprintw(15, 40, "-----------");
    rooms[2] = createRoom(40, 10, 6, 12);
    drawRoom(rooms[2]);

    return rooms;
}

Room *createRoom(int x, int y, int height, int width) {
    Room *newRoom;
    newRoom = malloc(sizeof(Room));
    // if memory cannot be allocated
    if (newRoom == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }
    newRoom->position.x = x;
    newRoom->position.y = y;
    newRoom->height = height;
    newRoom->width = width;
    return newRoom;
}

int drawRoom(Room *room) {
    int x, y;
    // draw top and bottom
    for (x = room->position.x; x < room->position.x + room->width; x++) {
        mvprintw(room->position.y, x, "-");                     // Top
        mvprintw(room->position.y + room->height - 1, x, "-");  // Bottom
    }
    // draw floors and side walls
    for (y = room->position.y + 1; y < room->position.y + room->height - 1;
         y++) {
        // draw side walls
        mvprintw(y, room->position.x, "|");
        mvprintw(y, room->position.x + room->width - 1, "|");
        // draw floors
        for (x = room->position.x + 1; x < room->position.x + room->width - 1;
             x++) {
            mvprintw(y, x, ".");
        }

        /* code */
    }

    return 1;
}