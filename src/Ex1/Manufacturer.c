
#include <stdlib.h>
#include "Manufacturer.h"

Manufacturer* createManufacturer(char* name, char* description, char* address, char* city, char* web, int phoneNumber, char* productName, char* productModel, int productPrice){
    Manufacturer* result = malloc(sizeof(Manufacturer));

    result->idGenerator=0;

    result->name=name;
    result->description=description;
    result->address=address;
    result->web=web;
    result->city=city;
    result->phoneNumber=phoneNumber;
    result->productModel=productModel;
    result->productName=productName;
    result->productPrice=productPrice;

    return result;
}

HouseholdAppliance* create_product(Manufacturer* manufacturer){
    HouseholdAppliance* result = createHouseholdAppliance(manufacturer->productName, manufacturer->productModel, manufacturer->productPrice);
    manufacturer->idGenerator++;
    result->id=manufacturer->idGenerator;
    return result;
}

void freeManufacturer(Manufacturer* manufacturer){
    free(manufacturer->name);
    free(manufacturer->description);
    free(manufacturer->city);
    free(manufacturer->address);
    free(manufacturer->web);
    free(manufacturer->productModel);
    free(manufacturer->productName);
    free(manufacturer);
}