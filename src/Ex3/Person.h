
#include "Borrowing.h"
#include "Material.h"

#ifndef TP_C_PERSON_H
#define TP_C_PERSON_H

typedef struct person Person;

struct person{
    char* personType;
    char* firstName;
    char* lastname;
    char* email;
    int phoneNumber;
    int id;

    Material* material;
    Borrowing* borrowing;
};

Person* createStudent(char* firstName, char* lastName, char* email, int phoneNumber, int id);
Person* createTeacher(char* firstName, char* lastName, char* email, int phoneNumber, int id);

void freePerson(Person* person);

#endif //TP_C_PERSON_H
