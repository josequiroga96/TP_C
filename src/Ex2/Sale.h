
#ifndef TP_C_SALE_H
#define TP_C_SALE_H

#include "LineSale.h"

typedef struct sale Sale;

struct sale{
    int code;
    int discount;

    LineSale** lineSale;
    int lineSaleAmount;
    int lineSaleCapacity;
};

Sale* createSale(int code, int discount, int capacity);

void addCamera(Sale* sale, Camera* camera, int quantity);
void addAccessory(Sale* sale, Accessory* accessory, int quantity);
void removeCamera(Sale* sale, char* name, int type, int quantity);
void removeAccessory(Sale* sale, char* name, int type, int quantity);

#endif //TP_C_SALE_H
