#include "Store.h"

int main() {
    // Create a vector of Store objects
    vector<Store> stores;

    // Create and add some sample stores
    stores.push_back(Store("CH0001", "Cua hang tien loi Quan 1", 2019, 10, 500000000, OperatingTime::HC));
    stores.push_back(Store("CH0002", "Cua hang tien loi Quan 2", 2020, 8, 250000000, OperatingTime::_247));
    stores.push_back(Store("CH0003", "Cua hang tien loi Quan 3", 2018, 12, 300000000, OperatingTime::HC));
    stores.push_back(Store("CH0004", "Cua hang tien loi Quan 4", 2015, 7, 150000000, OperatingTime::_247));
    stores.push_back(Store("CH0005", "Cua hang tien loi Quan 5", 2023, 11, 400000000, OperatingTime::_247));

    // Test the functions
    listStoresWithMoreThan10Employees(stores);
    deleteOldStoresWithLowRevenue(stores);
    calculateAverageRevenue(stores);

    return 0;
}
