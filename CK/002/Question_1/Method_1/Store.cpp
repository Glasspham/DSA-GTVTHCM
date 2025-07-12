#include "Store.h"
#include <algorithm> // Need this for std::remove_if
#include <numeric> // need this for std::accumulate

// a. Liệt kê các cửa hàng tiện lợi có số lượng nhân viên trên 10.
void listStoresWithMoreThan10Employees(vector<Store> stores) {
    cout << "Stores with more than 10 employees:\n";
    for (const auto& store : stores) {
        if (store.employeeCount > 10) {
            cout << "  Store Code: " << store.storeCode << ", Name: " << store.storeName
                 << ", Employee Count: " << store.employeeCount << "\n";
        }
    }
    cout << endl;
}

// b. Xóa các cửa hàng đã hoạt động trên 5 năm và doanh thu năm 2024 nhỏ hơn 200 triệu đồng
void deleteOldStoresWithLowRevenue(vector<Store>& stores) {
    int currentYear = 2024; // Assuming we're in 2024
    stores.erase(
        remove_if(stores.begin(), stores.end(), [&](const Store& store) {
            return (currentYear - store.foundingYear > 5) && (store.revenue2024 < 200000000);
        }),
        stores.end());
    cout << "Old store (more than 5 years, less than 200 million revenue) deleted\n" << endl;
}

// c. Tính trung bình doanh thu của các cửa hàng hoạt động 24/7 và các cửa hàng hoạt động giờ hành chính.
void calculateAverageRevenue(vector<Store> stores) {
    long long totalRevenue247 = 0;
    int count247 = 0;
    long long totalRevenueHC = 0;
    int countHC = 0;

    for (const auto& store : stores) {
        if (store.operatingTime == OperatingTime::_247) {
            totalRevenue247 += store.revenue2024;
            count247++;
        } else if(store.operatingTime == OperatingTime::HC) {
            totalRevenueHC += store.revenue2024;
            countHC++;
        }
    }

    cout << "Average Revenue (24/7): ";
    if (count247 > 0) {
        cout << static_cast<double>(totalRevenue247) / count247 << " VND\n";
    } else {
        cout << "No 24/7 stores found.\n";
    }

    cout << "Average Revenue (HC): ";
    if (countHC > 0) {
        cout << static_cast<double>(totalRevenueHC) / countHC << " VND\n";
    } else {
        cout << "No HC stores found.\n";
    }
    cout << endl;
}
