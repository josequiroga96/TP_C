
#ifndef TP_C_RSERVATION_H
#define TP_C_RSERVATION_H

typedef struct reservation Reservation;

struct reservation{
    int clientNumber;
    char* clientLastName;
    int clientID;
    int roomNumber;
};

Reservation* createReservation(int clientNumber, char* clientLastName, int clientID, int roomNumber);
void freeReservation(Reservation* reservation);

#endif //TP_C_RSERVATION_H
