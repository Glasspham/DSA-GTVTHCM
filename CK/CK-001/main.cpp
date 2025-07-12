#include "AVLTree.h"
#include <iostream>
using namespace std;

int main() {
    AVLTree system;
    // Thêm lịch hẹn mẫu
    system.addAppointment(Appointment("202505091000", "Nguyen Van A", "Nguyen Hoa Da", "Kham tong quat"));
    system.addAppointment(Appointment("202505091030", "Tran Quan Vu", "Le Van Sy", "Tu van dinh duong"));
    system.addAppointment(Appointment("202505091200", "Le Thi B", "Nguyen Hoa Da", "Kham mat"));
    // Hiển thị danh sách
    system.printAll();
    // Tìm kiếm theo tên
    cout << "\nTra cuu lich hen cua Tran Quan Vu:" << endl;
    system.searchByName("Tran Quan Vu");
    // Xóa lịch hẹn
    cout << "\nXoa lich hen 202505091030..." << endl;
    system.removeAppointment("202505091030");
    system.printAll();
    // Tìm kiếm theo ngày giờ
    cout << "\nTra cuu lich hen 202505091200:" << endl;
    system.searchByDatetime("202505091200");
    return 0;
}
