
#include <stdlib.h>
#include "Accessory.h"

Accessory* createAccessory(char* name, int code, int type, char* comment, int price){
    Accessory* result = malloc(sizeof(Accessory));

    result->name=name;
    result->code=code;
    result->type=type;
    result->comment=comment;
    result->price=price;

    return result;
}

void freeAccessory(Accessory* accessory){
    free(accessory->name);
    free(accessory->comment);
    free(accessory);
}