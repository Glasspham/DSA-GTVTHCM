#if 0 // Bài 1
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Cấu trúc lưu trữ thông tin sinh viên
struct Student {
    string email;
    string phone;
    int studentID;
};

// Bảng băm dùng `unordered_map` để lưu sinh viên theo tên
unordered_map<string, Student> studentTable;

// Hàm thêm sinh viên vào bảng băm
void insertStudent(string name, int id, string email, string phone) {
    studentTable[name] = {email, phone, id};
}

// Hàm tìm kiếm sinh viên theo tên
void searchStudent(string name) {
    auto it = studentTable.find(name);
    if (it != studentTable.end()) {
        cout << "Thong tin SV:\n";
        cout << "Ten: " << name << "\n";
        cout << "MSSV: " << it->second.studentID << "\n";
        cout << "Email: " << it->second.email << "\n";
        cout << "SDT: " << it->second.phone << "\n";
    } else cout << "Khong tim thay sinh vien.\n";
}

int main() {
    /* cout << "Nhap so luong sinh vien: ";
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string name, email, phone;
        int id;
        cout << "Nhap ten SV: ";
        getline(cin, name);
        cout << "Nhap MSSV: ";
        cin >> id;
        cin.ignore();
        cout << "Nhap email: ";
        getline(cin, email);
        cout << "Nhap so dien thoai: ";
        getline(cin, phone);
        insertStudent(name, id, email, phone);
    }
    string searchName;
    cout << "\nNhap ten SV can tim: ";
    getline(cin, searchName);
    searchStudent(searchName); */
    
    // Dữ liệu có sẵn
    insertStudent("Messi", 10, "messi@gmail.com", "0123456789");
    insertStudent("Ronaldo", 7, "cr7@gmail.com", "0987654321");
    insertStudent("Modric", 8, "modric@gmail.com", "0912345678");
    insertStudent("Xavi", 6, "xavi@gmail.com", "0934567890");
    insertStudent("Iniesta", 8, "iniesta@gmail.com", "0956789012");
    insertStudent("Neymar", 11, "neymar@gmail.com", "0978901234");

    // Tìm kiếm sinh viên
    searchStudent("Ronaldo");
    cout << "\n";
    searchStudent("Xavi");
    cout << "\n";
    searchStudent("Suarez");
    
    return 0;
}
#endif

#if 0 // Bài 2
#include <iostream>
#include <list>
#include <vector>
using namespace std;
struct Student {
    string name;
    string email;
    string phone;
    int studentID;
};
const int MAXN = 10;
vector<list<Student>> hashTable(MAXN);

// Hàm băm chuỗi theo mã ASCII
int hashFunction(string name) {
    int value = 0;
    for (char c : name) value += c;
    return value % MAXN;
}

// Hàm thêm sinh viên vào bảng băm
void insertStudent(string name, int id, string email, string phone) {
    int index = hashFunction(name);
    hashTable[index].push_back({name, email, phone, id});
}

// Hàm tìm kiếm sinh viên theo tên
void searchStudent(string name) {
    int index = hashFunction(name);
    for (Student s : hashTable[index]) {
        if (s.name == name) { // Kiểm tra chính xác tên
            cout << "Thong tin SV:\n";
            cout << "Ten: " << s.name << "\n";
            cout << "MSSV: " << s.studentID << "\n";
            cout << "Email: " << s.email << "\n";
            cout << "SDT: " << s.phone << "\n";
            return;
        }
    }
    cout << "Khong tim thay sinh vien.\n";
}

int main() {
    /* cout << "Nhap so luong sinh vien: ";
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string name, email, phone;
        int id;
        cout << "Nhap ten SV: ";
        getline(cin, name);
        cout << "Nhap MSSV: ";
        cin >> id;
        cin.ignore();
        cout << "Nhap email: ";
        getline(cin, email);
        cout << "Nhap so dien thoai: ";
        getline(cin, phone);
        insertStudent(name, id, email, phone);
    }
    string searchName;
    cout << "\nNhap ten SV can tim: ";
    getline(cin, searchName);
    searchStudent(searchName); */
    
    // Dữ liệu có sẵn
    insertStudent("Messi", 10, "messi@gmail.com", "0123456789");
    insertStudent("Ronaldo", 7, "cr7@gmail.com", "0987654321");
    insertStudent("Modric", 8, "modric@gmail.com", "0912345678");
    insertStudent("Xavi", 6, "xavi@gmail.com", "0934567890");
    insertStudent("Iniesta", 8, "iniesta@gmail.com", "0956789012");
    insertStudent("Neymar", 11, "neymar@gmail.com", "0978901234");

    // Tìm kiếm sinh viên
    searchStudent("Ronaldo");
    cout << "\n";
    searchStudent("Xavi");
    cout << "\n";
    searchStudent("Suarez");

    return 0;
}
#endif

#if 0 // Bài 3
#include <iostream>
#include <vector>
using namespace std;
struct Student {
    string name;
    string email;
    string phone;
    int studentID;
    bool isOccupied = false;
};
const int MAXN = 10;
vector<Student> hashTable(MAXN);

// Hàm băm chuỗi theo mã ASCII
int hashFunction(string name) {
    int value = 0;
    for (char c : name)
        value += c;
    return value % MAXN;
}

// Hàm chèn sinh viên vào bảng băm (Dò tuyến tính)
void insertStudent(string name, int id, string email, string phone) {
    int index = hashFunction(name);
    int originalIndex = index; // Lưu lại vị trí ban đầu để tránh vòng lặp vô hạn
    while (hashTable[index].isOccupied) { // Nếu vị trí đã có sinh viên khác
        index = (index + 1) % MAXN; // Dò tiếp vị trí kế tiếp (dò tuyến tính)
        if (index == originalIndex) { // Quay lại vị trí ban đầu, bảng băm đầy
            cout << "Bang bam day! Khong the chen them.\n";
            return;
        }
    }
    // Lưu thông tin sinh viên vào vị trí trống
    hashTable[index] = {name, email, phone, id, true};
}

// Hàm tìm kiếm sinh viên theo tên (Dò tuyến tính)
void searchStudent(string name) {
    int index = hashFunction(name);
    int originalIndex = index;
    while (hashTable[index].isOccupied) { // Chỉ kiểm tra ô đã có dữ liệu
        if (hashTable[index].name == name) { // Tìm thấy sinh viên
            cout << "Thong tin SV:\n";
            cout << "Ten: " << hashTable[index].name << "\n";
            cout << "MSSV: " << hashTable[index].studentID << "\n";
            cout << "Email: " << hashTable[index].email << "\n";
            cout << "SDT: " << hashTable[index].phone << "\n";
            return;
        }
        index = (index + 1) % MAXN; // Kiểm tra tiếp ô kế tiếp
        if (index == originalIndex) break; // Quay lại vị trí ban đầu => Không tìm thấy
    }
    cout << "Khong tim thay sinh vien.\n";
}

int main() {
    /* cout << "Nhap so luong sinh vien: ";
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string name, email, phone;
        int id;
        cout << "Nhap ten SV: ";
        getline(cin, name);
        cout << "Nhap MSSV: ";
        cin >> id;
        cin.ignore();
        cout << "Nhap email: ";
        getline(cin, email);
        cout << "Nhap so dien thoai: ";
        getline(cin, phone);
        insertStudent(name, id, email, phone);
    }
    string searchName;
    cout << "\nNhap ten SV can tim: ";
    getline(cin, searchName);
    searchStudent(searchName); */

    // Dữ liệu có sẵn
    insertStudent("Messi", 10, "messi@gmail.com", "0123456789");
    insertStudent("Ronaldo", 7, "cr7@gmail.com", "0987654321");
    insertStudent("Modric", 8, "modric@gmail.com", "0912345678");
    insertStudent("Xavi", 6, "xavi@gmail.com", "0934567890");
    insertStudent("Iniesta", 8, "iniesta@gmail.com", "0956789012");
    insertStudent("Neymar", 11, "neymar@gmail.com", "0978901234");

    // Tìm kiếm sinh viên
    searchStudent("Ronaldo");
    cout << "\n";
    searchStudent("Xavi");
    cout << "\n";
    searchStudent("Suarez");

    return 0;
}
#endif

#if 0 // Bài 4
#include <iostream>
#include <vector>
using namespace std;
struct Student {
    string name;
    string email;
    string phone;
    int studentID;
    bool isOccupied = false;
};
const int MAXN = 10;
vector<Student> hashTable(MAXN);

// Hàm băm chuỗi theo mã ASCII
int hashFunction(string name) {
    int value = 0;
    for (char c : name)
        value += c;
    return value % MAXN;
}

// Hàm chèn sinh viên vào bảng băm (Dò bậc 2)
void insertStudent(string name, int id, string email, string phone) {
    int index = hashFunction(name);
    int i = 1; // Biến kiểm soát bước nhảy bậc 2
    while (hashTable[index].isOccupied) { // Nếu vị trí đã có sinh viên khác
        index = (index + i * i) % MAXN; // Dò tiếp theo công thức bậc 2
        i++;
        if (i == MAXN) { // Tránh vòng lặp vô hạn nếu bảng băm đầy
            cout << "Bang bam day! Khong the chen them.\n";
            return;
        }
    }
    // Lưu thông tin sinh viên vào vị trí trống
    hashTable[index] = {name, email, phone, id, true};
}

// Hàm tìm kiếm sinh viên theo tên (Dò bậc 2)
void searchStudent(string name) {
    int index = hashFunction(name);
    int i = 1;
    while (hashTable[index].isOccupied) { // Chỉ kiểm tra ô đã có dữ liệu
        if (hashTable[index].name == name) { // Tìm thấy sinh viên
            cout << "Thong tin SV:\n";
            cout << "Ten: " << hashTable[index].name << "\n";
            cout << "MSSV: " << hashTable[index].studentID << "\n";
            cout << "Email: " << hashTable[index].email << "\n";
            cout << "SDT: " << hashTable[index].phone << "\n";
            return;
        }
        index = (index + i * i) % MAXN; // Kiểm tra tiếp ô kế tiếp theo bậc 2
        i++;
        if (i == MAXN) break; // Nếu vòng lặp quay về đầu => Không tìm thấy
    }
    cout << "Khong tim thay sinh vien.\n";
}

int main() {
    /* cout << "Nhap so luong sinh vien: ";
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string name, email, phone;
        int id;
        cout << "Nhap ten SV: ";
        getline(cin, name);
        cout << "Nhap MSSV: ";
        cin >> id;
        cin.ignore();
        cout << "Nhap email: ";
        getline(cin, email);
        cout << "Nhap so dien thoai: ";
        getline(cin, phone);
        insertStudent(name, id, email, phone);
    }
    string searchName;
    cout << "\nNhap ten SV can tim: ";
    getline(cin, searchName);
    searchStudent(searchName); */

    // Dữ liệu có sẵn
    insertStudent("Messi", 10, "messi@gmail.com", "0123456789");
    insertStudent("Ronaldo", 7, "cr7@gmail.com", "0987654321");
    insertStudent("Modric", 8, "modric@gmail.com", "0912345678");
    insertStudent("Xavi", 6, "xavi@gmail.com", "0934567890");
    insertStudent("Iniesta", 8, "iniesta@gmail.com", "0956789012");
    insertStudent("Neymar", 11, "neymar@gmail.com", "0978901234");

    // Tìm kiếm sinh viên
    searchStudent("Ronaldo");
    cout << "\n";
    searchStudent("Xavi");
    cout << "\n";
    searchStudent("Suarez");

    return 0;
}
#endif

#if 0 // Bài 5
#include <iostream>
#include <vector>
using namespace std;
struct Student {
    string name;
    string email;
    string phone;
    int studentID;
    bool isOccupied = false;
};
const int MAXN = 11;
vector<Student> hashTable(MAXN);

// Hàm băm chính (chuyển tên thành chỉ số trong bảng băm)
int hash1(string name) {
    int value = 0;
    for (char c : name)
        value += c;
    return value % MAXN;
}

// Hàm băm phụ để tạo bước nhảy khi đụng độ
int hash2(string name) {
    int value = 0;
    for (char c : name)
        value = (value * 31 + c) % MAXN;
    return (value % (MAXN - 1)) + 1; // Đảm bảo bước nhảy luôn > 0
}

// Hàm chèn sinh viên vào bảng băm (Băm kép)
void insertStudent(string name, int id, string email, string phone) {
    int index = hash1(name);
    int step = hash2(name);
    int i = 0; // Số lần thử
    while (hashTable[index].isOccupied) { // Nếu vị trí đã có sinh viên khác
        index = (index + i * step) % MAXN; // Áp dụng công thức băm kép
        i++;
        if (i == MAXN) { // Tránh vòng lặp vô hạn nếu bảng đầy
            cout << "Bang bam day! Khong the chen them.\n";
            return;
        }
    }
    // Lưu thông tin sinh viên vào vị trí trống
    hashTable[index] = {name, email, phone, id, true};
}

// Hàm tìm kiếm sinh viên theo tên (Băm kép)
void searchStudent(string name) {
    int index = hash1(name);
    int step = hash2(name);
    int i = 0;
    while (hashTable[index].isOccupied) { // Chỉ kiểm tra ô đã có dữ liệu
        if (hashTable[index].name == name) { // Tìm thấy sinh viên
            cout << "Thong tin SV:\n";
            cout << "Ten: " << hashTable[index].name << "\n";
            cout << "MSSV: " << hashTable[index].studentID << "\n";
            cout << "Email: " << hashTable[index].email << "\n";
            cout << "SDT: " << hashTable[index].phone << "\n";
            return;
        }
        index = (index + i * step) % MAXN; // Kiểm tra tiếp ô kế tiếp theo băm kép
        i++;
        if (i == MAXN) break; // Nếu vòng lặp quay về đầu => Không tìm thấy
    }
    cout << "Khong tim thay sinh vien.\n";
}

int main() {
    /* cout << "Nhap so luong sinh vien: ";
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string name, email, phone;
        int id;
        cout << "Nhap ten SV: ";
        getline(cin, name);
        cout << "Nhap MSSV: ";
        cin >> id;
        cin.ignore();
        cout << "Nhap email: ";
        getline(cin, email);
        cout << "Nhap so dien thoai: ";
        getline(cin, phone);
        insertStudent(name, id, email, phone);
    }
    string searchName;
    cout << "\nNhap ten SV can tim: ";
    getline(cin, searchName);
    searchStudent(searchName); */

    // Dữ liệu có sẵn
    insertStudent("Messi", 10, "messi@gmail.com", "0123456789");
    insertStudent("Ronaldo", 7, "cr7@gmail.com", "0987654321");
    insertStudent("Modric", 8, "modric@gmail.com", "0912345678");
    insertStudent("Xavi", 6, "xavi@gmail.com", "0934567890");
    insertStudent("Iniesta", 8, "iniesta@gmail.com", "0956789012");
    insertStudent("Neymar", 11, "neymar@gmail.com", "0978901234");

    // Tìm kiếm sinh viên
    searchStudent("Ronaldo");
    cout << "\n";
    searchStudent("Xavi");
    cout << "\n";
    searchStudent("Suarez");

    return 0;
}
#endif