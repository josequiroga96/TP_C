
#include <stdlib.h>
#include "LineCart.h"

LineCart* createLineCart(int id, HouseholdAppliance* product, int quantity){
    LineCart* result = malloc(sizeof(LineCart));

    result->id=id;
    result->product=product;
    result->quantity=quantity;

    return result;
}

void freeLineCart(LineCart* lineCart){
    freeHouseholdAppliance(lineCart->product);
    free(lineCart);
}