
#include <stdlib.h>
#include "Library.h"

Library* createLibrary(int personsCapacity, int materialsCapacity){
    Library* result = malloc(sizeof(Library));

    result->materialsAmount=0;
    result->personsAmount=0;
    result->generatorIDforBorrowing=0;
    result->personsCapacity=personsCapacity;
    result->materialsCapacity=materialsCapacity;

    result->materials = malloc(sizeof(Material*)*result->materialsCapacity);
    result->persons = malloc(sizeof(Person*)*result->personsCapacity);

    return result;
}

static void growPersons(Library* library){
    int capacity = (library->personsCapacity)*2;
    library->persons = realloc(library->persons, sizeof(Person*)*capacity);
    library->personsCapacity=capacity;
}

static void growMaterials(Library* library){
    int capacity = (library->materialsCapacity)*2;
    library->materials = realloc(library->materials, sizeof(Material*)*capacity);
    library->materialsCapacity=capacity;
}

void addMaterial(Library* library, Material* material){
    if(library->materialsCapacity==library->materialsAmount)
        growMaterials(library);
    library->materials[library->materialsAmount]=material;
    library->materialsAmount++;
}

void addPerson(Library* library, Person* person){
    if(library->personsCapacity==library->personsAmount)
        growPersons(library);
    library->persons[library->personsAmount]=person;
    library->personsAmount++;
}

Borrowing* make_Borrowing(Library* library, Person* person, char* materialType, int materialCode, char* borrowingDate, char* returnDate){
    for(int i=0; i<library->materialsAmount; i++){
        if(library->materials[i]->type==materialType && library->materials[i]->code==materialCode)
            library->materials[i]->available=0;
    }
    return createBorrowing(library->generatorIDforBorrowing, materialCode, materialType, borrowingDate, returnDate);
}

void acceptReturn(Library* library, Borrowing* borrowing){
    for(int i=0; i<library->materialsAmount; i++){
        if(library->materials[i]->type==borrowing->materialType && library->materials[i]->code==borrowing->materialCode)
            library->materials[i]->available=1;
    }
    freeBorrowing(borrowing);
}

void freeLibrary(Library* library){
    for(int i=0; i< library->materialsAmount; i++)
        freeMaterial(library->materials[i]);
    for(int i=0; i< library->personsAmount; i++)
        freePerson(library->persons[i]);
    free(library);
}