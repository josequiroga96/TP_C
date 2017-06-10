
#ifndef TP_C_CLIENT_H
#define TP_C_CLIENT_H

#include "Rental.h"

typedef struct client Client;

struct client{
    char* clientName;
    char* clientLastName;
    int clientID;
    Rental* rental;
};

Client* createClient(char* clientName, char* clientLastName, int clientID);
void freeClient(Client* client);

#endif //TP_C_CLIENT_H
