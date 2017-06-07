
#ifndef TP_C_BORROWING_H
#define TP_C_BORROWING_H

typedef struct borrowing Borrowing;

struct borrowing{
    int id;
    int materialCode;
    char* materialType;
    char* borrowingDate;
    char* returnDate;
};

Borrowing* createBorrowing(int id, int materialCode, char* materialType, char* borrowingDate, char* returnDate);
void freeBorrowing(Borrowing* borrowing);

#endif //TP_C_BORROWING_H
