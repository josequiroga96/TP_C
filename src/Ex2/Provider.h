
#ifndef TP_C_PROVIDER_H
#define TP_C_PROVIDER_H

#include "Camera.h"
#include "Accessory.h"

typedef struct provider Provider;

struct provider{
    char* name;
    char* responsible;
    char* address;
    char* city;
    char* country;
    int zipCode;
    int phoneNumber;
    int fax;
};

Provider* createProvider(char* name, char* responsible, char* address, char* city, char* country, int zipCode, int phoneNumber, int fax);

Camera** provideCamera(Provider* provider, int quantity, char* name, int code, int megaPixels, int screenSize, int opticalZoom, int type, int price);
Accessory** provideAccesory(Provider* provider, int quantity, char* name, int code, int type, char* comment, int price);

void freeProvider(Provider* provider);

#endif //TP_C_PROVIDER_H
