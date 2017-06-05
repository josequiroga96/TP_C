
#include <stdlib.h>
#include "LineTicket.h"

LineTicket* createLineTicket(int id, HouseholdAppliance* product, int quantity){
    LineTicket* result = malloc(sizeof(LineTicket));

    result->id=id;
    result->product=product;
    result->quantity=quantity;

    return result;
}

void freeLineTicket(LineTicket* lineTicket){
    freeHouseholdAppliance(lineTicket->product);
    free(lineTicket);
}