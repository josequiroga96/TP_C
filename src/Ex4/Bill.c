
#include <stdlib.h>
#include "Bill.h"

Bill* createBill(char* hotelName, char* clientName, int billCode, int hotelNit, int clientID, int value){
    Bill* result = malloc(sizeof(Bill));

    result->hotelName=hotelName;
    result->clientName=clientName;
    result->billCode=billCode;
    result->hotelNit=hotelNit;
    result->clientID=clientID;
    result->value=value;

    return result;
}

void freeBill(Bill* bill){
    free(bill->hotelName);
    free(bill->clientName);
    free(bill);
}