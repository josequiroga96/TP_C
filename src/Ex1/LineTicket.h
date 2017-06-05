
#ifndef TP_C_LINETICKET_H
#define TP_C_LINETICKET_H

#include "HouseholdAppliance.h"

typedef struct lineTicket LineTicket;

struct lineTicket{
    int id;
    HouseholdAppliance* product;
    int quantity;
};

LineTicket* createLineTicket(int id, HouseholdAppliance* product, int quantity);
void freeLineTicket(LineTicket* lineTicket);

#endif //TP_C_LINETICKET_H
