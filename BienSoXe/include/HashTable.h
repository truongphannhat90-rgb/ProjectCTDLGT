#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>

using namespace std;

struct LicenseNode {
    string license;
    string province;
    string ward;   
    LicenseNode* next;
};

class HashTable {
private:
    static const int TABLE_SIZE = 100;
    LicenseNode* table[TABLE_SIZE];

    int hashFunction(const string& province, const string& ward);

public:
    HashTable();
    ~HashTable();

    void insert(const string& license);
    bool search(const string& license);
    void displayWardsByProvince(const string& province);
    void displayLicensesByWard(const string& province, const string& ward);
    void loadFromFile(const string& filename);
};

#endif
