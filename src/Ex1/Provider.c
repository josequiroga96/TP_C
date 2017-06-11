
#include <stdlib.h>
#include "Provider.h"


Provider* createProvider(char* name, char* description, char* address, char* city, char* web, int phoneNumber, int capacity){
    Provider* result = malloc(sizeof(Provider));

    result->name=name;
    result->description=description;
    result->address=address;
    result->web=web;
    result->city=city;
    result->phoneNumber=phoneNumber;

    result->hAListAmount=0;
    result->hAListCapacity=capacity;

    result->hAList = malloc(sizeof(HouseholdAppliance*)*result->hAListCapacity);

    return result;
}

static void growProduct(Provider* provider){
    int capacity = (provider->hAListCapacity)*2;
    provider->hAList = realloc(provider->hAList, sizeof(HouseholdAppliance*)*capacity);
    provider->hAListCapacity=capacity;
}

int add__Product(Provider* provider, HouseholdAppliance* hA){
    if(provider->hAListCapacity==provider->hAListAmount)
        growProduct(provider);
    provider->hAList[provider->hAListAmount]=hA;
    provider->hAListAmount++;
    return 1;
}

void remove__Product(Provider* provider, char* name, char* model){
    for(int i = 0; i < provider->hAListAmount; i++){
        if((provider->hAList[i]->name == name) && (provider->hAList[i]->model == model) ){
            freeHouseholdAppliance(provider->hAList[i]);
            for(; i < provider->hAListAmount-1; i++){
                provider->hAList[i] = provider->hAList[i+1];
            }
            provider->hAListAmount--;
            break;
        }
    }
}

HouseholdAppliance** provideHouseholdApplience(Provider* provider, char* name, char* model, int quantity, Manufacturer* manufacturer){
    HouseholdAppliance** result = malloc(quantity* sizeof(HouseholdAppliance*));

    for(int i = 0; i < provider->hAListAmount; i++){
        if((provider->hAList[i]->name == name) && (provider->hAList[i]->model == model) ) {
            for (int j = 0; j < quantity; j++) {
                result[j] = create_product(manufacturer);
            }
            break;
        }
    }

    return result;
}

void freeProvider(Provider* provider){
    for(int i=0; provider->hAListAmount; i++){
        freeHouseholdAppliance(provider->hAList[i]);
    }

    free(provider->name);
    free(provider->description);
    free(provider->address);
    free(provider->city);
    free(provider->web);
    free(provider);
}