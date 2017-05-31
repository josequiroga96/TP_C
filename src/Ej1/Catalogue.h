
#ifndef TP_C_CATALOGUE_H
#define TP_C_CATALOGUE_H

#include "HouseholdAppliance.h"

typedef struct catalogue Catalogue;

struct catalogue{
    int id;
    char* name;
    int discount;

    HouseholdAppliance** hAList;
    int hAListCapacity;
    int hAListAmount;
};

Catalogue* createCatalogue(int id, char* name, int discount, int capacity);

int addProduct(Catalogue* catalogue, HouseholdAppliance* hA);
void removeProduct(Catalogue* catalogue, char* name, char* model);
Catalogue* setDiscount(Catalogue* catalogue, int newDiscount);

void freeCatalogue(Catalogue* catalogue);

#endif //TP_C_CATALOGUE_H
