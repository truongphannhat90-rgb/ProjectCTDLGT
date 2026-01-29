#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "LicensePlate.h"

#define MAX_PLATES 100

struct ManageLicensePlate
{
    LicensePlate plates[MAX_PLATES];
    int count;
};

void initManageLicensePlate(ManageLicensePlate& m);
void addLicensePlate(ManageLicensePlate& m);
void printLicensePlate(const ManageLicensePlate& m);
int findLicensePlate(const ManageLicensePlate& m, int id);

void sortByProvinceCode(ManageLicensePlate& m);
void sortByWardCode(ManageLicensePlate& m);

#endif
