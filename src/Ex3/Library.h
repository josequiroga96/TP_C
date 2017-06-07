
#ifndef TP_C_LIBRARY_H
#define TP_C_LIBRARY_H

#include "Person.h"

typedef struct library Library;

struct library{
    int generatorIDforBorrowing;

    Person** persons;
    int personsAmount;
    int personsCapacity;

    Material** materials;
    int materialsAmount;
    int materialsCapacity;
};

Library* createLibrary(int personsCapacity, int materialsCapacity);

void addMaterial(Library* library, Material* material);
void addPerson(Library* library, Person* person);

Borrowing* make_Borrowing(Library* library, Person* person, char* materialType, int materialCode, char* borrowingDate, char* returnDate);
void acceptReturn(Library* library, Borrowing* borrowing);

void freeLibrary(Library* library);

#endif //TP_C_LIBRARY_H
