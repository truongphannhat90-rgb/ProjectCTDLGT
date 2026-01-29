#include "HashTable.h"
#include <iostream>
#include <fstream>

using namespace std;

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        LicenseNode* curr = table[i];
        while (curr != nullptr) {
            LicenseNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
}

int HashTable::hashFunction(const string& province, const string& ward) {
    int key = stoi(province + ward);
    return key % TABLE_SIZE;
}

void HashTable::insert(const string& license) {
    string province = license.substr(0, 2);
    string ward = license.substr(3, 2);

    int index = hashFunction(province, ward);

    LicenseNode* newNode = new LicenseNode;
    newNode->license = license;
    newNode->province = province;
    newNode->ward = ward;
    newNode->next = table[index];

    table[index] = newNode;
}

bool HashTable::search(const string& license) {
    string province = license.substr(0, 2);
    string ward = license.substr(3, 2);
    int index = hashFunction(province, ward);

    LicenseNode* curr = table[index];
    while (curr != nullptr) {
        if (curr->license == license)
            return true;
        curr = curr->next;
    }
    return false;
}

void HashTable::displayWardsByProvince(const string& province) {
    cout << "Danh sach ma Xa cua Tinh " << province << ":\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        LicenseNode* curr = table[i];
        while (curr != nullptr) {
            if (curr->province == province) {
                cout << curr->ward << endl;
            }
            curr = curr->next;
        }
    }
}

void HashTable::displayLicensesByWard(const string& province, const string& ward) {
    cout << "Danh sach bien so cua Xa " << ward
         << " - Tinh " << province << ":\n";

    int index = hashFunction(province, ward);
    LicenseNode* curr = table[index];

    while (curr != nullptr) {
        if (curr->province == province && curr->ward == ward) {
            cout << curr->license << endl;
        }
        curr = curr->next;
    }
}

void HashTable::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Khong mo duoc file!\n";
        return;
    }

    string license;
    while (getline(file, license)) {
        if (!license.empty()) {
            insert(license);
        }
    }

    file.close();
}
