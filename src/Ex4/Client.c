
#include <stdlib.h>
#include "Client.h"
#include "Receptionist.h"


Client* createClient(char* name, char* lastName, int clientID){
    Client* result = malloc(sizeof(Client));

    result->clientID=clientID;
    result->name=name;
    result->lastName=lastName;

    return result;
}

void make_Reservation(Client* client, Receptionist* receptionist, char* roomType){
    makeReservation(receptionist, client->lastName, client->clientID, roomType);
}

void askForBill(Client* client, Receptionist* receptionist){
    makeBill(receptionist, client);
}

void freeClient(Client* client){
    free(client->name);
    free(client->lastName);
    free(client);
}