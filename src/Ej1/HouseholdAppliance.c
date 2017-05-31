#include <stdlib.h>
#include "HouseholdAppliance.h"

HouseholdAppliance* createHouseholdAppliance(char* name, char* model, int price){
    HouseholdAppliance* result = malloc(sizeof(HouseholdAppliance));

    result->name=name;
    result->model=model;
    result->price=price;

    return result;
}

HouseholdAppliance* setPrice(HouseholdAppliance* hA, int newPrice){
    hA->price=newPrice;

    return hA;
}

void freeHouseholdAppliance(HouseholdAppliance* hA){
    free(hA->name);
    free(hA->model);
    free(hA);
}