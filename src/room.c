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

    connectDoors(rooms[0]->doors[3], rooms[3]->doors[1]);

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

    newRoom->doors = malloc(sizeof(Position) * 4);
    if (newRoom->doors == NULL) {
        printf("Error! Memory not allocated.");
        exit(0);
    }

    // Creating doors
    // Top door
    newRoom->doors[0] = malloc(sizeof(Position));
    newRoom->doors[0]->x = rand() % (width - 2) + newRoom->position.x + 1;
    newRoom->doors[0]->y = newRoom->position.y;

    // Left door
    newRoom->doors[1] = malloc(sizeof(Position));
    newRoom->doors[1]->y = rand() % (height - 2) + newRoom->position.y + 1;
    newRoom->doors[1]->x = newRoom->position.x;

    // Bottom door
    newRoom->doors[2] = malloc(sizeof(Position));
    newRoom->doors[2]->x = rand() % (width - 2) + newRoom->position.x + 1;
    newRoom->doors[2]->y = newRoom->position.y + newRoom->height - 1;

    // Right door
    newRoom->doors[3] = malloc(sizeof(Position));
    newRoom->doors[3]->y = rand() % (height - 2) + newRoom->position.y + 1;
    newRoom->doors[3]->x = newRoom->position.x + width - 1;

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
    }

    // Draw doors
    mvprintw(room->doors[0]->y, room->doors[0]->x, "+");
    mvprintw(room->doors[1]->y, room->doors[1]->x, "+");
    mvprintw(room->doors[2]->y, room->doors[2]->x, "+");
    mvprintw(room->doors[3]->y, room->doors[3]->x, "+");

    return 1;
}

int connectDoors(Position *doorOne, Position *doorTwo) {
    Position temp;
    temp.x = doorOne->x;
    temp.y = doorOne->y;

    while (true) {
        // Step left
        if ((abs((temp.x - 1) - doorTwo->x) < abs(temp.x - doorTwo->x)) &&
            (mvinch(temp.y, temp.x - 1) == ' ')) {
            mvprintw(temp.y, temp.x - 1, "#");
            temp.x = temp.x - 1;
        // Step right
        } else if ((abs((temp.x + 1) - doorTwo->x) <
                    abs(temp.x - doorTwo->x)) &&
                   (mvinch(temp.y, temp.x + 1) == ' ')) {
            mvprintw(temp.y, temp.x + 1, "#");
            temp.x = temp.x + 1;
        // Step down
        } else if ((abs((temp.y + 1) - doorTwo->y) <
                    abs(temp.y - doorTwo->y)) &&
                   (mvinch(temp.y + 1, temp.x) == ' ')) {
            mvprintw(temp.y + 1, temp.x, "#");
            temp.y = temp.y + 1;
        // Step up
        } else if ((abs((temp.y - 1) - doorTwo->y) <
                    abs(temp.y - doorTwo->y)) &&
                   (mvinch(temp.y - 1, temp.x) == ' ')) {
            mvprintw(temp.y - 1, temp.x, "#");
            temp.y = temp.y - 1;
        }else {
            return 0;
        }
        getch();
    }

    return 1;
}