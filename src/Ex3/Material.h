
#ifndef TP_C_MATERIAL_H
#define TP_C_MATERIAL_H

typedef struct material Material;


struct material{
    char* type;
    int code;
    char* author;
    char* tittle;
    int year;
    char* status;
    char* editorial;
    int available;
};

Material* createBook(int code, char* author, char* tittle, int year, char* status, char* editorial);
Material* createMagazine(int code, char* author, char* tittle, int year, char* status, char* editorial);

void borrowMaterial(Material* material);
void returnMaterial(Material* material);

void freeMaterial(Material* material);

#endif //TP_C_MATERIAL_H
