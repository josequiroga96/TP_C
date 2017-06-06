
#ifndef TP_C_REGISTEREDUSER_H
#define TP_C_REGISTEREDUSER_H

#include "Sale.h"

typedef struct registeredUser RegisteredUser;

struct registeredUser{
    char* name;
    int id;
    char* address;
    int phone;
    char* locality;
    char* province;
    char* country;
    int zipCode;
    int role;

    Sale** sales;
    int salesAmount;
    int salesCapacity;
};

RegisteredUser* createRegisteredUser(char* name, int id, char* address, int phone, char* locality, char* province, char* country, int zipCode, int role);
void buyProducts(RegisteredUser* registeredUser, Sale* sale);
void freeRegisteredUser(RegisteredUser* registeredUser);


#endif //TP_C_REGISTEREDUSER_H

