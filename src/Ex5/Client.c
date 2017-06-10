
#include <stdlib.h>
#include "Client.h"
#include "Administrator.h"

Client* createClient(char* clientName, char* clientLastName, int clientID){
    Client* result = malloc(sizeof(Client));

    result->clientName=clientName;
    result->clientLastName=clientLastName;
    result->clientID=clientID;

    return result;
}

void rentMovie(Client* client, Administrator* administrator, char* movieName, char* rentalDate, char* returnDate){
   client->rental =rentalMovie(administrator,client,movieName,rentalDate, returnDate);
}

void returnMovie(Client* client, Administrator* administrator){
    getMovieBack(administrator, client->rental);
}

int check_MovieAvailability(Client* client, Administrator* administrator, char* movieName){
    return checkMovieAvailability(administrator,movieName);
}

void freeClient(Client* client){
    freeRental(client->rental);
    free(client->clientName);
    free(client->clientLastName);
    free(client);
}