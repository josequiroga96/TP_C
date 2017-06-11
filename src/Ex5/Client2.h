
#ifndef TP_C_CLIENT_H
#define TP_C_CLIENT_H

#include "Rental.h"

typedef struct client2 Client2;

struct client2{
    char* clientName;
    char* clientLastName;
    int clientID;
    Rental* rental;
};

Client2* createClient2(char* clientName, char* clientLastName, int clientID);
void freeClient2(Client2* client);

#endif //TP_C_CLIENT_H
