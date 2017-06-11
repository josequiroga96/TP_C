
#include <stdlib.h>
#include "Cart.h"

Cart* createCart(int id, int lineCartCapacity){
    Cart* result = malloc(sizeof(Cart));

    result->id=id;
    result->lineCartCapacity=lineCartCapacity;
    result->lineCartAmount=0;

    result->lineCarts= malloc(sizeof(LineCart*)*result->lineCartCapacity);

    return result;
}

static void grow(Cart* cart){
    int capacity = (cart->lineCartCapacity)*2;
    cart->lineCarts = realloc(cart->lineCarts, sizeof(LineCart*)*capacity);
    cart->lineCartCapacity=capacity;
}

void addProduct(Cart* cart, LineCart* lineCart){
    if(cart->lineCartCapacity==cart->lineCartAmount)
        grow(cart);
    cart->lineCarts[cart->lineCartAmount]=lineCart;
    cart->lineCartAmount++;
}

void removeProduct(Cart* cart, HouseholdAppliance* householdAppliance, int quantity){
    for(int i=0; i < cart->lineCartAmount; i++){
        if(cart->lineCarts[i]->product->name==householdAppliance->name && cart->lineCarts[i]->product->model==householdAppliance->model){
            quantity=cart->lineCarts[i]->quantity-quantity;
            cart->lineCarts[i]->quantity= quantity;
        }
        break;
    }
}

Ticket* getTicket(Cart* cart){ //destroy Cart
    Ticket* result = createTicket(cart->id, cart->lineCartCapacity);

    for(int i=0; i< cart->lineCartAmount; i++){
        LineTicket* auxLine = createLineTicket(cart->id, cart->lineCarts[i]->product, cart->lineCarts[i]->quantity);
        addLine(result, auxLine);
    }
    return result;
}

void freeCart(Cart* cart){
    for(int i=0; cart->lineCartAmount; i++){
        freeLineCart(cart->lineCarts[i]);
    }
    free(cart);
}