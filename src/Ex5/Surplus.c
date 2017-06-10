
#include <stdlib.h>
#include "Surplus.h"

Surplus* createSurplus(int rentalPrice){
    Surplus* result = malloc(sizeof(Surplus));

    result->amount=rentalPrice;

    return result;
}

void earnMoney(Surplus* surplus, int moneyEarned){
    surplus->depositMoney=moneyEarned;
}

void freeSurplus(Surplus* surplus){
    free(surplus);
}