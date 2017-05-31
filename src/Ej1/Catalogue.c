
#include <stdlib.h>
#include "Catalogue.h"

Catalogue* createCatalogue(int id, char* name, int discount, int capacity){
    Catalogue* result = malloc(sizeof(Catalogue));

    result->name=name;
    result->id=id;
    result->discount=discount;

    result->hAListAmount=0;
    result->hAListCapacity=capacity;

    result->hAList = malloc(sizeof(HouseholdAppliance*)*result->hAListCapacity);

    return result;
}

static void growProduct(Catalogue* catalogue){
    int capacity = (catalogue->hAListCapacity)*2;
    catalogue->hAList = realloc(catalogue->hAList, sizeof(HouseholdAppliance*)*capacity);
    catalogue->hAListCapacity=capacity;
}

int addProduct(Catalogue* catalogue, HouseholdAppliance* hA){
    if(catalogue->hAListCapacity==catalogue->hAListAmount)
        growProduct(catalogue);
    catalogue->hAList[catalogue->hAListAmount]=hA;
    catalogue->hAListAmount++;
    return 1;
}

void removeProduct(Catalogue* catalogue, char* name, char* model){
    for(int i = 0; i < catalogue->hAListAmount; i++){
        if((catalogue->hAList[i]->name == name) && (catalogue->hAList[i]->model == model) ){
            freeHouseholdAppliance(catalogue->hAList[i]);
            for(; i < catalogue->hAListAmount-1; i++){
                catalogue->hAList[i] = catalogue->hAList[i+1];
            }
            catalogue->hAListAmount--;
            break;
        }
    }
}

Catalogue* setDiscount(Catalogue* catalogue, int newDiscount){
    catalogue->discount=newDiscount;
    return catalogue;
}

void freeCatalogue(Catalogue* catalogue){
    for(int i=0; catalogue->hAListAmount; i++){
        freeHouseholdAppliance(catalogue->hAList[i]);
    }

    free(catalogue->name);
    free(catalogue);
}