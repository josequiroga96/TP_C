
#ifndef TP_C_RECEPTIONIST_H
#define TP_C_RECEPTIONIST_H

#include "Room.h"
#include "Client.h"
#include "Reservation.h"
#include "Bill.h"

typedef struct receptionist Receptionist;

struct receptionist{
    char* receptionistName;
    char* receptionistLastName;
    int receptionistID;
    int hotelNit;
    char* hotelName;

    Room** rooms;
    int roomAmount;
    int roomCapacity;

    Client** clients;
    int clientAmount;
    int clientCapacity;

    Reservation** reservations;
    int reservationAmount;
    int reservationCapacity;

    int generatorClientNumber;
    int generatorBillCode;
};

Receptionist* createReceptionist(char* receptionistName, char* receptionistLastName, char* hotelName, int recepcionistID, int hotelNit, Room** rooms, int capacity);

Reservation* makeReservation(Receptionist* receptionist, char* clientLastName, int clientID, char* roomType);
Bill* makeBill(Receptionist* receptionist, Client* client);

void freeReceptionist(Receptionist* receptionist);

#endif //TP_C_RECEPTIONIST_H
