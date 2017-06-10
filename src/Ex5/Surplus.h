
#ifndef TP_C_SURPLUS_H
#define TP_C_SURPLUS_H

typedef struct surplus Surplus;

struct surplus{
    int amount;
    int depositMoney;
};

Surplus* createSurplus(int rentalPrice);
void earnMoney(Surplus* surplus, int moneyEarned);
void freeSurplus(Surplus* surplus);

#endif //TP_C_SURPLUS_H
