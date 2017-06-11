
#ifndef TP_C_CART_H
#define TP_C_CART_H

#include "LineCart.h"
#include "Ticket.h"

typedef struct cart Cart;

struct cart{
    int id;

    LineCart** lineCarts;
    int lineCartCapacity;
    int lineCartAmount;
};

Cart* createCart(int id, int lineCartCapacity);

void addProduct(Cart* cart, LineCart* lineCart);
void removeProduct(Cart* cart, HouseholdAppliance* householdAppliance, int quantity);

Ticket* getTicket(Cart* cart); //destroy Cart

#endif //TP_C_CART_H
