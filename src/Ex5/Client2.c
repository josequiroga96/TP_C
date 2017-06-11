
#include <stdlib.h>
#include "Client2.h"
#include "Administrator.h"

Client2* createClient2(char* clientName, char* clientLastName, int clientID){
    Client2* result = malloc(sizeof(Client2));

    result->clientName=clientName;
    result->clientLastName=clientLastName;
    result->clientID=clientID;

    return result;
}

void rentMovie(Client2* client, Administrator* administrator, char* movieName, char* rentalDate, char* returnDate){
   client->rental =rentalMovie(administrator,client,movieName,rentalDate, returnDate);
}

void returnMovie(Client2* client, Administrator* administrator){
    getMovieBack(administrator, client->rental);
}

int check_MovieAvailability(Client2* client, Administrator* administrator, char* movieName){
    return checkMovieAvailability(administrator,movieName);
}

void freeClient2(Client2* client){
    freeRental(client->rental);
    free(client->clientName);
    free(client->clientLastName);
    free(client);
}