
#include <stdlib.h>
#include "Provider2.h"

Provider2* createProvider2(char* name, char* responsible, char* address, char* city, char* country, int zipCode, int phoneNumber, int fax){
    Provider2* result = malloc(sizeof(Provider2));

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

Camera** provideCamera(Provider2* provider, int quantity, char* name, int code, int megaPixels, int screenSize, int opticalZoom, int type, int price){
    Camera** result= malloc(sizeof(Camera*)*quantity);

    for(int i=0; i<quantity;i++){
        result[i]=createCamera(name, code, megaPixels, screenSize, opticalZoom, type, price);
    }

    return result;
}
Accessory** provideAccesory(Provider2* provider, int quantity, char* name, int code, int type, char* comment, int price){
    Accessory** result= malloc(sizeof(Accessory*)*quantity);

    for(int i=0; i<quantity;i++){
        result[i]=createAccessory(name, code, type, comment, price);
    }

    return result;
}

void freeProvider2(Provider2* provider){
    free(provider->name);
    free(provider->responsible);
    free(provider->address);
    free(provider->city);
    free(provider->country);
    free(provider);
}