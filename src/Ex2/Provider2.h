
#ifndef TP_C_PROVIDER2_H
#define TP_C_PROVIDER2_H

#include "Camera.h"
#include "Accessory.h"

typedef struct provider2 Provider2;

struct provider2{
    char* name;
    char* responsible;
    char* address;
    char* city;
    char* country;
    int zipCode;
    int phoneNumber;
    int fax;
};

Provider2* createProvider2(char* name, char* responsible, char* address, char* city, char* country, int zipCode, int phoneNumber, int fax);

Camera** provideCamera(Provider2* provider, int quantity, char* name, int code, int megaPixels, int screenSize, int opticalZoom, int type, int price);
Accessory** provideAccesory(Provider2* provider, int quantity, char* name, int code, int type, char* comment, int price);

void freeProvider2(Provider2* provider);

#endif //TP_C_PROVIDER_H
