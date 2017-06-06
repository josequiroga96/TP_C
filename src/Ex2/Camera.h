
#ifndef TP_C_CAMERA_H
#define TP_C_CAMERA_H

typedef struct camera Camera;

struct camera{
    char* name;
    int code;
    int megaPixels;
    int screenSize;
    int opticalZoom;
    int type;
    int price;
};

Camera* createCamera(char* name, int code, int megaPixels, int screenSize, int opticalZoom, int type, int price);
void freeCamera(Camera* camera);

#endif //TP_C_CAMERA_H
