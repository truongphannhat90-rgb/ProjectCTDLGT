#ifndef LICENSE_PLATE_H
#define LICENSE_PLATE_H

#include <iostream>
#include <string>

using namespace std;

struct LicensePlate {
    string plateNumber;    
    string ownerName;      
    string vehicleType;   
    LicensePlate* next;    
    LicensePlate();
    LicensePlate(string plate, string owner, string type);
    void display();
};

#endif
