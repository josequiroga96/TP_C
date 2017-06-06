
#include <stdlib.h>
#include "Provider.h"

Provider* createProvider(char* name, char* responsible, char* address, char* city, char* country, int zipCode, int phoneNumber, int fax){
    Provider* result = malloc(sizeof(Provider));

    result->name=name;
    result->responsible=responsible;
    result->address=address;
    result->country=country;
    result->city=city;
    result->phoneNumber=phoneNumber;
    result->zipCode=zipCode;
    result->fax=fax;

    return result;
}

Camera** provideCamera(Provider* provider, int quantity, char* name, int code, int megaPixels, int screenSize, int opticalZoom, int type, int price){
    Camera** result= malloc(sizeof(Camera*)*quantity);

    for(int i=0; i<quantity;i++){
        result[i]=createCamera(name, code, megaPixels, screenSize, opticalZoom, type, price);
    }

    return result;
}
Accessory** provideAccesory(Provider* provider, int quantity, char* name, int code, int type, char* comment, int price){
    Accessory** result= malloc(sizeof(Accessory*)*quantity);

    for(int i=0; i<quantity;i++){
        result[i]=createAccessory(name, code, type, comment, price);
    }

    return result;
}

void freeProvider(Provider* provider){
    free(provider->name);
    free(provider->responsible);
    free(provider->address);
    free(provider->city);
    free(provider->country);
    free(provider);
}