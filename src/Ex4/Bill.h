
#ifndef TP_C_BILL_H
#define TP_C_BILL_H

typedef struct bill Bill;

struct bill{
    int billCode;
    int hotelNit;
    char* hotelName;
    char* clientName;
    int clientID;
    int value;
};

Bill* createBill(char* hotelName, char* clientName, int billCode, int hotelNit, int clientID, int value);
void freeBill(Bill* bill);

#endif //TP_C_BILL_H
