
#ifndef TP_C_PROVIDER_H
#define TP_C_PROVIDER_H

#include "HouseholdAppliance.h"
#include "Manufacturer.h"

typedef struct provider Provider;

struct provider{
    char* name;
    char* description;
    char* address;
    char* city;
    char* web;
    int phoneNumber;

    HouseholdAppliance** hAList;
    int hAListCapacity;
    int hAListAmount;
};

Provider* createProvider(char* name, char* description, char* address, char* city, char* web, int phoneNumber, int capacity);

int addProduct(Provider* provider, HouseholdAppliance* hA);
void removeProduct(Provider* provider, char* name, char* model);

HouseholdAppliance** provideHouseholdApplience(Provider* provider, char* name, char* model, int quantity, Manufacturer* manufacturer);

void freeProvider(Provider* provider);

#endif //TP_C_PROVIDER_H
