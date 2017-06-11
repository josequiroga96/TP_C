
#include "Camera.h"
#include "Accessory.h"

#ifndef TP_C_MANUFACTURER2_H
#define TP_C_MANUFACTURER2_H

typedef struct manufacturer2 Manufacturer2;

struct manufacturer2{
    char* name;
    int code;
};

Manufacturer2* createManufacturer2(char* name, int code);

Camera* makeCamera(char* name, int code, int megaPixels, int screenSize, int opticalZoom, int type, int price);
Accessory* makeAccessory(char* name, int code, int type, char* comment, int price);

void freeAccessory(Accessory* accessory);

#endif //TP_C_MANUFACTURER_H
