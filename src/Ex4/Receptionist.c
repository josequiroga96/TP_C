
#include <stdlib.h>
#include "Receptionist.h"

Receptionist* createReceptionist(char* receptionistName, char* receptionistLastName, char* hotelName, int recepcionistID, int hotelNit, Room** rooms, int capacity){
    Receptionist* result = malloc(sizeof(Receptionist));

    result->receptionistName=receptionistName;
    result->receptionistLastName=receptionistLastName;
    result->hotelName=hotelName;
    result->receptionistID=recepcionistID;
    result->hotelNit=hotelNit;
    result->rooms=rooms;
    result->roomCapacity= sizeof(result->roomCapacity)*2;
    result->clientCapacity=capacity;
    result->reservationCapacity=capacity;

    result->roomAmount=sizeof(result->roomCapacity);
    result->clientAmount=0;
    result->reservationAmount=0;
    result->generatorClientNumber=0;
    result->generatorBillCode=0;

    return result;
}

static int getRoom(Receptionist* receptionist){
    for(int i =0; i< receptionist->roomAmount; i++)
        if(receptionist->rooms[i]->clienteNumber == -1)
            return receptionist->rooms[i]->number;
    return -1;
}


Reservation* makeReservation(Receptionist* receptionist, char* clientLastName, int clientID, char* roomType){
    int roomNumber = getRoom(receptionist);
    Reservation* result= createReservation(receptionist->generatorClientNumber,clientLastName,clientID,roomNumber);
    receptionist->rooms[roomNumber]->isReserved=1;
    receptionist->rooms[roomNumber]->clienteNumber=receptionist->generatorClientNumber;
    receptionist->generatorClientNumber++;
    receptionist->reservations[receptionist->reservationAmount]=result;
    receptionist->reservationAmount++;
    return result;
}

Bill* makeBill(Receptionist* receptionist, Client* client){
    Bill* result = createBill(receptionist->hotelName, client->name,receptionist->generatorBillCode,receptionist->hotelNit,client->clientID,1500);
    receptionist->clients[receptionist->clientAmount]=client;
    receptionist->clientAmount++;
    return result;
}

void freeReceptionist(Receptionist* receptionist){
    for(int i=0; i < receptionist->clientAmount; i++){
        freeClient(receptionist->clients[i]);
    }
    for(int i=0; i < receptionist->roomAmount; i++){
        freeRoom(receptionist->rooms[i]);
    }
    for(int i=0; i < receptionist->reservationAmount; i++){
        freeReservation(receptionist->reservations[i]);
    }
    free(receptionist->receptionistName);
    free(receptionist->receptionistLastName);
    free(receptionist->hotelName);
    free(receptionist);
}