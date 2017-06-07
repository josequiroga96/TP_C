
#include <stdlib.h>
#include "Borrowing.h"

Borrowing* createBorrowing(int id, int materialCode, char* materialType, char* borrowingDate, char* returnDate){
    Borrowing* result = malloc(sizeof(Borrowing));

    result->id=id;
    result->materialCode=materialCode;
    result->materialType=materialType;
    result->borrowingDate=borrowingDate;
    result->returnDate=returnDate;

    return result;
}

void freeBorrowing(Borrowing* borrowing){
    free(borrowing->materialCode);
    free(borrowing->materialType);
    free(borrowing->borrowingDate);
    free(borrowing->returnDate);
    free(borrowing);
}