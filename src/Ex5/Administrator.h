
#ifndef TP_C_ADMINISTRATOR_H
#define TP_C_ADMINISTRATOR_H

#include "Client2.h"

typedef struct administrator Administrator;

struct administrator{
    char* administratorName;
    char* administratorLastName;
    int administratorID;

    char** movies;
    int movieAmount;
    int movieCapacity;

    char** rentedMovies;
    int rMAmount;
    int rMCapacity;

    Client2** clients;
    int clientAmount;
    int clientCapacity;

    Rental** rentals;
    int rentalAmount;
    int rentalCapacity;
};

Administrator* createAdministrator(char* administratorName, char* administratorLastName, int administratorID, char** movies, int capacity);

void registeredClient(Administrator* administrator, Client2* client);
Rental* rentalMovie(Administrator* administrator, Client2* client, char* movieName, char* rentalDate, char* returnDate);
void getMovieBack(Administrator* administrator, Rental* rental);
int checkMovieAvailability(Administrator* administrator, char* movieName);

void freeAdministrator(Administrator* administrator);

#endif //TP_C_ADMINISTRATOR_H
