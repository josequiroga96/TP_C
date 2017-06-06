
#ifndef TP_C_LINESALE_H
#define TP_C_LINESALE_H

#include "Accessory.h"
#include "Camera.h"

typedef struct lineSale LineSale;

struct lineSale{
    int code;
    int quantity;

    Camera* camera;
    Accessory* accessory;
};

LineSale* createCameraLineSale(int code, int quantity, Camera* camera);
void freeCameraLineSale(LineSale* cameraLineSale);

LineSale* createAccessoryLineSale(int code, int quantity, Accessory* accessory);
void freeAccessoryLineSale(LineSale* accessoryLineSale);

#endif //TP_C_LINESALE_H
