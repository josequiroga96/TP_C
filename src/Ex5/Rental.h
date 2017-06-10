
#ifndef TP_C_RENTAL_H
#define TP_C_RENTAL_H

typedef struct rental Rental;

struct rental{
    char* movieName;
    int clientID;
    char* rentalDate;
    char* returnDate;
};

Rental* createRental(char* movieName, int clientID, char* rentalDate, char* returnDate);
void freeRental(Rental* rental);

#endif //TP_C_RENTAL_H
