
#include <stdlib.h>
#include "Sale.h"


Sale* createSale(int code, int discount, int capacity){
    Sale* result= malloc(sizeof(Sale));

    result->code=code;
    result->discount=discount;
    result->lineSaleCapacity=capacity;
    result->lineSaleAmount=0;

    result->lineSale=malloc(sizeof(LineSale*)*result->lineSaleCapacity);

    return result;
}

static void grow(Sale* sale){
    int capacity = (sale->lineSaleCapacity)*2;
    sale->lineSale = realloc(sale->lineSale, sizeof(LineSale*)*capacity);
    sale->lineSaleCapacity=capacity;
}

void addCamera(Sale* sale, Camera* camera, int quantity){
    if(sale->lineSaleCapacity==sale->lineSaleAmount)
        grow(sale);
    sale->lineSale[sale->lineSaleAmount]=createCameraLineSale(sale->code, quantity, camera);
    sale->lineSaleAmount++;
}

void addAccessory(Sale* sale, Accessory* accessory, int quantity){
    if(sale->lineSaleCapacity==sale->lineSaleAmount)
        grow(sale);
    sale->lineSale[sale->lineSaleAmount]=createAccessoryLineSale(sale->code, quantity, accessory);
    sale->lineSaleAmount++;
}
void removeCamera(Sale* sale, char* name, int type, int quantity){
    for(int i = 0; i < sale->lineSaleAmount; i++){
        if( ((sale->lineSale[i]->camera->name == name) && (sale->lineSale[i]->camera->type == type))){
            freeCameraLineSale(sale->lineSale[i]);
            for(; i < sale->lineSaleAmount-1; i++){
                sale->lineSale[i] = sale->lineSale[i+1];
            }
            sale->lineSaleAmount--;
            break;
        }
    }
}

void removeAccessory(Sale* sale, char* name, int type, int quantity){
    for(int i = 0; i < sale->lineSaleAmount; i++){
        if( ((sale->lineSale[i]->accessory->name == name) && (sale->lineSale[i]->accessory->type == type))){
            freeAccessoryLineSale(sale->lineSale[i]);
            for(; i < sale->lineSaleAmount-1; i++){
                sale->lineSale[i] = sale->lineSale[i+1];
            }
            sale->lineSaleAmount--;
            break;
        }
    }
}
