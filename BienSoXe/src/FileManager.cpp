#include "FileManager.h"

void initManageLicensePlate(ManageLicensePlate& m)
{
	m.count = 0;
}

void addLicensePlate(ManageLicensePlate& m)
{
    if (m.count >= MAX_PLATES)
    {
        cout << "Danh sach da day!\n";
        return;
    }

    LicensePlate& lp = m.plates[m.count];

    cout << "Nhap ID: ";
    cin >> lp.id;

    cout << "Nhap ma tinh (provinceCode): ";
    cin >> lp.provinceCode;

    cout << "Nhap ma phuong (wardCode): ";
    cin >> lp.wardCode;

    m.count++;
    cout << "Them bien so thanh cong!\n";
}

void printLicensePlate(const ManageLicensePlate& m)
{
    if (m.count == 0)
    {
        cout << "Chua co bien so nao!\n";
        return;
    }

    for (int i = 0; i < m.count; i++)
    {
        cout << "\nBien so thu " << i + 1 << endl;
        cout << "ID: " << m.plates[i].id << endl;
        cout << "Province: " << m.plates[i].provinceCode << endl;
        cout << "Ward: " << m.plates[i].wardCode << endl;
    }
}

int findLicensePlate(const ManageLicensePlate& m, int id)
{
    for (int i = 0; i < m.count; i++)
    {
        if (m.plates[i].id == id)
            return i;
    }
    return -1;
}

void sortByProvinceCode(ManageLicensePlate& m)
{
    int n = m.count;

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            LicensePlate temp = m.plates[i];
            int j;

            for (j = i; j >= gap &&
                m.plates[j - gap].provinceCode > temp.provinceCode;
                j -= gap)
            {
                m.plates[j] = m.plates[j - gap];
            }

            m.plates[j] = temp;
        }
    }
    cout << "Danh sach bien so xe theo tinh: " << endl;
}

void sortByWardCode(ManageLicensePlate& m)
{
    int n = m.count;

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            LicensePlate temp = m.plates[i];
            int j;

            for (j = i; j >= gap &&
                m.plates[j - gap].wardCode > temp.wardCode;
                j -= gap)
            {
                m.plates[j] = m.plates[j - gap];
            }

            m.plates[j] = temp;
        }
    }
    cout << "Danh sach bien so xe theo xa: " << endl;
}
