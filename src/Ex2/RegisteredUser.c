
#include <stdlib.h>
#include "RegisteredUser.h"


RegisteredUser* createRegisteredUser(char* name, int id, char* address, int phone, char* locality, char* province, char* country, int zipCode, int role){
    RegisteredUser* result = malloc(sizeof(RegisteredUser));

    result->name=name;
    result->id=id;
    result->address=address;
    result->phone=phone;
    result->locality=locality;
    result->province=province;
    result->country=country;
    result->zipCode=zipCode;
    result->role=role;

    result->salesAmount=0;
    result->salesCapacity=50;

    result->sales=malloc(sizeof(Sale*)*result->salesCapacity);

    return result;
}

void grow(RegisteredUser* registeredUser){
    int capacity= registeredUser->salesCapacity*2;
    registeredUser->sales=realloc(registeredUser->sales, sizeof(Sale*)*capacity);
    registeredUser->salesCapacity=capacity;
}

void buyProducts(RegisteredUser* registeredUser, Sale* sale){
    if(registeredUser->salesCapacity==registeredUser->salesAmount)
        grow(registeredUser);
    registeredUser->sales[registeredUser->salesAmount]=sale;
    registeredUser->salesAmount++;
}

void freeRegisteredUser(RegisteredUser* registeredUser){
    free(registeredUser->name);
    free(registeredUser->address);
    free(registeredUser->locality);
    free(registeredUser->province);
    free(registeredUser->country);
    free(registeredUser);
}