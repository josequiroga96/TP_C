
#include <stdlib.h>
#include "Manufacturer.h"

Manufacturer* createManufacturer(char* name, int code){
    Manufacturer* result = malloc(sizeof(Manufacturer));

    result->name=name;
    result->code=code;

    return result;
}

Camera* makeCamera(char* name, int code, int megaPixels, int screenSize, int opticalZoom, int type, int price){
    return createCamera(name, code, megaPixels, screenSize, opticalZoom, type, price);
}

Accessory* makeAccessory(char* name, int code, int type, char* comment, int price){
    return createAccessory(name, code, type, comment, price);
}

void freeManufacturer(Manufacturer* manufacturer){
    free(manufacturer->name);
    free(manufacturer);
}