
#ifndef TP_C_HOUSEHOLDAPPLIANCE_H
#define TP_C_HOUSEHOLDAPPLIANCE_H


typedef struct householdAppliance HouseholdAppliance;

struct householdAppliance{
    char* name;
    char* model;
    int price;
    int id;

};

HouseholdAppliance* createHouseholdAppliance(char* name, char* model, int price);
void freeHouseholdAppliance(HouseholdAppliance* hA);

#endif //TP_C_HOUSEHOLDAPPLIANCE_H
