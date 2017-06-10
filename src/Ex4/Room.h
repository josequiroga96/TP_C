
#ifndef TP_C_ROOM_H
#define TP_C_ROOM_H

typedef struct room Room;

struct room{
    int number;
    char* roomType;
    int clienteNumber;
    int isReserved;
};

Room* createRoom(int number, char* roomType);

void accommodateClient(Room* room, int clientNumber);
void reserveRoom(Room* room);
void emptyRoom(Room* room);

void freeRoom(Room* room);

#endif //TP_C_ROOM_H
