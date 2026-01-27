#include "LicensePlate.h"

LicensePlate::LicensePlate() {
    plateNumber = "";
    ownerName = "";
    vehicleType = "";
    next = nullptr;
}

LicensePlate::LicensePlate(string plate, string owner, string type) {
    plateNumber = plate;
    ownerName = owner;
    vehicleType = type;
    next = nullptr;
}

void LicensePlate::display() {
    cout << "Bien so: " << plateNumber << endl;
    cout << "Chu xe : " << ownerName << endl;
    cout << "Loai xe: " << vehicleType << endl;
    cout << "---------------------------" << endl;
}
