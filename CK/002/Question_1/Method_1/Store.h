#pragma once
#ifndef STORE_H
#define STORE_H
#include <iostream>
#include <string>
#include <vector> // Need this for std::vector

using namespace std;

// Define an enum for the operating time
enum class OperatingTime {
    HC, // Giờ hành chính (Office Hours)
    _247 // 24/7
};

// Structure to represent a convenience store
class Store {
public:
    string storeCode;          // Mã cửa hàng (e.g., CH0001)
    string storeName;          // Tên (e.g., Cửa hàng tiện lợi Quận 1)
    int foundingYear;       // Năm thành lập (e.g., 2019)
    int employeeCount;       // Số lượng nhân viên (e.g., 10)
    long long revenue2024;  // Doanh thu năm 2024 (e.g., 500000000 for 500 million)
    OperatingTime operatingTime; // Thời gian hoạt động (HC or 247)

    // Optionally add a constructor:
    Store(string code, string name, int year, int count, long long revenue, OperatingTime time) :
        storeCode(code), storeName(name), foundingYear(year), employeeCount(count), revenue2024(revenue), operatingTime(time) {}
    
    Store(){
        storeCode="";
        storeName="";
        foundingYear=0;
        employeeCount=0;
        revenue2024=0;
        operatingTime = OperatingTime::HC;
    }

};

// Function prototypes (we'll define them in a separate .cpp file)
void listStoresWithMoreThan10Employees(vector<Store> stores);
void deleteOldStoresWithLowRevenue(vector<Store>& stores);
void calculateAverageRevenue(vector<Store> stores);
#endif // STORE_H