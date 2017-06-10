
#include <stdlib.h>
#include "Room.h"


Room* createRoom(int number, char* roomType){
    Room* result= malloc(sizeof(Room));

    result->number=number;
    result->roomType=roomType;
    result->clienteNumber=-1;
    result->isReserved=0;

    return result;
}

void accommodateClient(Room* room, int clientNumber){
    room->clienteNumber=clientNumber;
}

void reserveRoom(Room* room){
    room->isReserved=1;
}
void emptyRoom(Room* room){
    room->isReserved=0;
    room->clienteNumber=-1;
}

void freeRoom(Room* room){
    free(room->roomType);
    free(room);
}