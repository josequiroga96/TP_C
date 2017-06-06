
#include <stdlib.h>
#include "LineSale.h"

LineSale* createAccessoryLineSale(int code, int quantity, Accessory* accessory){
    LineSale* result = malloc(sizeof(LineSale));

    result->code=code;
    result->quantity=quantity;
    result->accessory=accessory;

    return result;
}

void freeAccessoryLineSale(LineSale* accessoryLineSale){
    freeAccessory(accessoryLineSale->accessory);
    free(accessoryLineSale);
}

LineSale* createCameraLineSale(int code, int quantity, Camera* camera){
    LineSale* result = malloc(sizeof(LineSale));

    result->code=code;
    result->quantity=quantity;
    result->camera=camera;

    return result;
}

void freeCameraLineSale(LineSale* cameraLineSale){
    freeCamera(cameraLineSale->camera);
    free(cameraLineSale);
}