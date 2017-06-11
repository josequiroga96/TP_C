
#include <stdlib.h>
#include "Manufacturer2.h"

Manufacturer2* createManufacturer2(char* name, int code){
    Manufacturer2* result = malloc(sizeof(Manufacturer2));

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

void freeManufacturer(Manufacturer2* manufacturer){
    free(manufacturer->name);
    free(manufacturer);
}