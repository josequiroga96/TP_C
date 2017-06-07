
#include <stdlib.h>
#include "Person.h"
#include "Library.h"

Person* createStudent(char* firstName, char* lastName, char* email, int phoneNumber, int id){
    Person* result = malloc(sizeof(Person));

    result->personType="student";

    result->firstName=firstName;
    result->lastname=lastName;
    result->email=email;
    result->phoneNumber=phoneNumber;
    result->id=id;

    return result;
}

Person* createTeacher(char* firstName, char* lastName, char* email, int phoneNumber, int id){
    Person* result = malloc(sizeof(Person));

    result->personType="teacher";

    result->firstName=firstName;
    result->lastname=lastName;
    result->email=email;
    result->phoneNumber=phoneNumber;
    result->id=id;

    return result;
}

void makeBorrowing(Person* person, Library* library, char* materialType, int code, char* borrowingDate, char* returnDate){
    person->borrowing = make_Borrowing(library, person, materialType, code, borrowingDate, returnDate);
}

void returnBorrowing(Library* library, Borrowing* borrowing){
    acceptReturn(library, borrowing);
}

void freePerson(Person* person){
    freeBorrowing(person->borrowing);
    freeMaterial(person->material);
    free(person->personType);
    free(person->firstName);
    free(person->lastname);
    free(person->email);
    free(person);
}