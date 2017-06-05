
#ifndef TP_C_MANUFACTURER_H
#define TP_C_MANUFACTURER_H

#include "HouseholdAppliance.h"

typedef struct manufacturer Manufacturer;

struct manufacturer{
    char* name;
    char* description;
    char* address;
    char* city;
    char* web;
    int phoneNumber;

    char* productName;
    char* productModel;
    int productPrice;
    int idGenerator;
};

Manufacturer* createManufacturer(char* name, char* description, char* address, char* city, char* web, int phoneNumber, char* productName, char* productModel, int productPrice);
HouseholdAppliance* create_product(Manufacturer* manufacturer);
void freeManufacturer(Manufacturer* manufacturer);



#endif //TP_C_MANUFACTURER_H
