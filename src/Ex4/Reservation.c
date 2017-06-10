
#include <stdlib.h>
#include "Reservation.h"


Reservation* createReservation(int clientNumber, char* clientLastName, int clientID, int roomNumber){
    Reservation* result = malloc(sizeof(Reservation));

    result->clientNumber=clientNumber;
    result->clientLastName=clientLastName;
    result->clientID=clientID;
    result->roomNumber=roomNumber;

    return result;
}

void freeReservation(Reservation* reservation){
    free(reservation->clientLastName);
    free(reservation);
}