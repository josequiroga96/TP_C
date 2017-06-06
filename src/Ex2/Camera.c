
#include <stdlib.h>
#include "Camera.h"

Camera* createCamera(char* name, int code, int megaPixels, int screenSize, int opticalZoom, int type, int price){
    Camera* result= malloc(sizeof(Camera));

    result->name=name;
    result->code;
    result->megaPixels=megaPixels;
    result->screenSize=screenSize;
    result->opticalZoom=opticalZoom;
    result->type=type;
    result->price=price;

    return result;
}

void freeCamera(Camera* camera){
    free(camera->name);
    free(camera);
}