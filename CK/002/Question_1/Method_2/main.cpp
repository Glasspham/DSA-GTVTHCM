#include "AVLTree.h"

int main() {
    AVLTree storeTree;

    storeTree.insert(new Store("CH0001", "Cua hang tien loi quan 1", 2019, 10, 500, "HC"));
    storeTree.insert(new Store("CH0002", "Cua hang tien loi quan 2", 2020, 8, 250, "247"));
    storeTree.insert(new Store("CH0003", "Cua hang tien loi quan 3", 2015, 12, 180, "247"));
    storeTree.insert(new Store("CH0004", "Cua hang tien loi quan 4", 2018, 15, 300, "HC"));
    storeTree.insert(new Store("CH0005", "Cua hang tien loi quan 5", 2016, 5, 120, "247"));
    storeTree.insert(new Store("CH0006", "Cua hang tien loi quan 6", 2021, 20, 400, "HC"));
    storeTree.insert(new Store("CH0007", "Cua hang tien loi quan 7", 2014, 7, 90, "HC"));
    storeTree.insert(new Store("CH0008", "Cua hang tien loi quan 8", 2023, 25, 600, "247"));
    storeTree.insert(new Store("CH0009", "Cua hang tien loi quan 9", 2017, 9, 210, "HC"));
    storeTree.insert(new Store("CH0010", "Cua hang tien loi quan 10", 2013, 11, 50, "247"));

    storeTree.inOrder();
    
    cout << "\nDanh sach cua hang tien loi co so luong nhan vien tren 10:\n";
    storeTree.listStoresWithEmployeesGreaterThan(10);
    
    cout << "\nXoa cua hang tren 5 nam va doanh thu nam 2024 < 200 trieu\n";
    storeTree.removeOldLowRevenueStores(5, 2024, 200);
    storeTree.inOrder();  // Hiển thị lại danh sách sau khi xóa

    cout << "\nDoanh thu trung binh cua hang hoat dong 24/7: " << storeTree.averageRevenueByOperationTime("247") << " trieu\n";
    cout << "Doanh thu trung binh cua hang gio hanh chinh: " << storeTree.averageRevenueByOperationTime("HC") << " trieu\n";

    return 0;
}
