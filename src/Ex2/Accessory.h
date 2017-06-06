
#ifndef TP_C_ACCESSORY_H
#define TP_C_ACCESSORY_H

typedef struct accessory Accessory;

struct accessory{
    char* name;
    int code;
    int type;
    char* comment;
    int price;
};

Accessory* createAccessory(char* name, int code, int type, char* comment, int price);
void freeAccessory(Accessory* accessory);

#endif //TP_C_ACCESSORY_H
