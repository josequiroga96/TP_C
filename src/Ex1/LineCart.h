
#ifndef TP_C_LINECART_H
#define TP_C_LINECART_H

#include "HouseholdAppliance.h"

typedef struct lineCart LineCart;

struct lineCart{
    int id;
    HouseholdAppliance* product;
    int quantity;
};

LineCart* createLineCart(int id, HouseholdAppliance* product, int quantity);
void freeLineCart(LineCart* lineCart);

#endif //TP_C_LINECART_H
