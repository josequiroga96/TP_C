
#ifndef TP_C_CLIENT_H
#define TP_C_CLIENT_H

typedef struct client Client;

struct client{
    char* name;
    char* lastName;
    int clientID;
};

Client* createClient(char* name, char* lastName, int clientID);
void freeClient(Client* client);

#endif //TP_C_CLIENT_H
