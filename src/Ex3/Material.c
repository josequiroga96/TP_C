
#include <stdlib.h>
#include "Material.h"


Material* createBook(int code, char* author, char* tittle, int year, char* status, char* editorial){
    Material* result = malloc(sizeof(Material));

    result->type="book";

    result->code=code;
    result->author=author;
    result->tittle=tittle;
    result->year=year;
    result->status=status;
    result->editorial=editorial;

    return result;
}

Material* createMagazine(int code, char* author, char* tittle, int year, char* status, char* editorial){
    Material* result = malloc(sizeof(Material));

    result->type="magazine";

    result->code=code;
    result->author=author;
    result->tittle=tittle;
    result->year=year;
    result->status=status;
    result->editorial=editorial;

    return result;
}

void borrowMaterial(Material* material){
    material->available=0;
}

void returnMaterial(Material* material){
    material->available=1;
}

void freeMaterial(Material* material){
    free(material->type);
    free(material->author);
    free(material->tittle);
    free(material->status);
    free(material->editorial);
    free(material);
}