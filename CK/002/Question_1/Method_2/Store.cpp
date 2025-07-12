#include "Store.h"

Store::Store(string id, string name, int yearFounded, int employees, double revenue2024, string operationTime)
    : id(id), name(name), yearFounded(yearFounded), employees(employees), revenue2024(revenue2024), operationTime(operationTime) {}

void Store::display() const {
    cout << "Id: " << id << "\n"
         << "Ten: " << name << "\n"
         << "Nam thanh lap: " << yearFounded << "\n"
         << "So luong nhan vien: " << employees << "\n"
         << "Doanh thu nam 2024: " << revenue2024 << " trieu\n"
         << "Thoi gian hoat dong: " << (operationTime == "HC" ? "Gio hanh chinh" : "24/7") << "\n"
         << "---------------------------------\n";
}
