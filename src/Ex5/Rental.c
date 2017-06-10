
#include <stdlib.h>
#include "Rental.h"


Rental* createRental(char* movieName, int clientID, char* rentalDate, char* returnDate){
    Rental* result = malloc(sizeof(Rental));

    result->movieName=movieName;
    result->clientID=clientID;
    result->rentalDate=rentalDate;
    result->returnDate=returnDate;

    return result;
}

void freeRental(Rental* rental){
    free(rental->movieName);
    free(rental->rentalDate);
    free(rental->returnDate);
    free(rental);
}