// ! Tự viết hàm sort có sẵn
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;

// Hàm in mảng
void PrintArray(int a[], int N) {
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << endl;
}

// 1. Sắp xếp tăng dần
void SortAscending(int a[], int N) {
    sort(a, a + N);
}

// 2. Tìm số lớn thứ 3
int FindThirdLargest(int a[], int N) {
    SortAscending(a, N);
    int max1 = a[N - 1], count = 1;
    for (int i = N - 2; i >= 0; i--) {
        if (a[i] < max1) {
            count++;
            max1 = a[i];
            if (count == 3) return max1;
        }
    }
    return -1; // Không có số lớn thứ 3
}

// 3. Đếm số lượng phần tử lớn nhất
int CountMaxOccurrences(int a[], int N) {
    SortAscending(a, N);
    int maxVal = a[N - 1], count = 0;
    for (int i = N - 1; i >= 0 && a[i] == maxVal; i--)
        count++;
    return count;
}

// 4. Sắp xếp theo trị tuyệt đối tăng dần
void SortByAbsoluteValue(int a[], int N) {
    sort(a, a + N, [](int x, int y) {
        return abs(x) < abs(y);
    });
}

// 5. Sắp xếp số dương giảm dần, số âm tăng dần
void SortPositiveNegative(int a[], int N) {
    sort(a, a + N, [](int x, int y) {
        if (x >= 0 && y >= 0) return x > y;
        if (x < 0 && y < 0) return x < y;
        return x > y;
    });
}

// 6. Chẵn tăng dần, lẻ giảm dần
void SortEvenOdd(int a[], int N) {
    sort(a, a + N, [](int x, int y) {
        if (x % 2 == 0 && y % 2 == 0) return x < y;
        if (x % 2 != 0 && y % 2 != 0) return x > y;
        return x % 2 == 0;
    });
}

// 7. Sắp xếp theo vị trí chẵn/lẻ ban đầu
void SortEvenOddStable(int a[], int N) {
    int even[N], odd[N], evenIdx = 0, oddIdx = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] % 2 == 0) even[evenIdx++] = a[i];
        else odd[oddIdx++] = a[i];
    }
    sort(even, even + evenIdx);
    sort(odd, odd + oddIdx, greater<int>());
    evenIdx = 0, oddIdx = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] % 2 == 0) a[i] = even[evenIdx++];
        else a[i] = odd[oddIdx++];
    }
}

// 8. Tạo một cấu trúc dữ liệu để xử lý danh sách trên.
struct Student {
    int id;
    string fullName;
    int birthYear;
    string getLastName() const {
        size_t pos = fullName.find_last_of(' ');
        if(pos == string::npos) return fullName;
        return fullName.substr(pos + 1);
    }
};

// Hàm hiển thị danh sách sinh viên
void printStudents(const vector<Student>& students) {
    cout << "STT\tMSSV\tHo va ten\t\tNam sinh\n";
    for (size_t i = 0; i < students.size(); i++)
        cout << i + 1 << "\t" << students[i].id << "\t" 
             << students[i].fullName << "\t\t" << students[i].birthYear << "\n";
    cout << "------------------------------------------------\n";
}

// 9. Hàm sắp xếp danh sách theo MSSV tăng dần
void sortByID(vector<Student>& students) {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.id < b.id;
    });
}

// 10. Hàm sắp xếp danh sách theo tên (thứ tự bảng chữ cái), nếu trùng thì theo năm sinh tăng dần
void sortByNameAndBirthYear(vector<Student>& students) {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.getLastName() != b.getLastName())
            return a.getLastName() < b.getLastName();
        return a.birthYear < b.birthYear;
    });
}

int main() {
    int A[] = {12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15};
    int N = sizeof(A) / sizeof(A[0]);

    // 1. Sắp xếp tăng dần
    SortAscending(A, N);
    cout << "1. Tang dan: ";
    PrintArray(A, N);

    // 2. Số lớn thứ 3
    int thirdLargest = FindThirdLargest(A, N);
    cout << "2. So lon thu 3: " << thirdLargest << endl;

    // 3. Số lượng phần tử lớn nhất
    int maxCount = CountMaxOccurrences(A, N);
    cout << "3. So lan xuat hien so lon nhat: " << maxCount << endl;

    // 4. Sắp xếp theo giá trị tuyệt đối tăng dần
    int B[] = {12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15};
    SortByAbsoluteValue(B, N);
    cout << "4. Sap xep theo tri tuyet doi: ";
    PrintArray(B, N);

    // 5. Sắp xếp số dương giảm dần, số âm tăng dần
    int C[] = {12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15};
    SortPositiveNegative(C, N);
    cout << "5. So duong giam dan, so am tang dan: ";
    PrintArray(C, N);

    // 6. Sắp xếp chẵn tăng dần, lẻ giảm dần
    int D[] = {12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15};
    SortEvenOdd(D, N);
    cout << "6. Chan tang dan, le giam dan: ";
    PrintArray(D, N);

    // 7. Sắp xếp chẵn tăng dần, lẻ giảm dần nhưng giữ vị trí ban đầu
    int E[] = {12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15};
    SortEvenOddStable(E, N);
    cout << "7. Giu vi tri chan/le, chan tang dan, le giam dan: ";
    PrintArray(E, N);

    // 8. Tạo một cấu trúc dữ liệu để xử lý danh sách trên.
    vector<Student> students = {
        {1005, "Tran Minh Thanh", 1991},
        {1001, "Tran Thi Bich", 1988},
        {1003, "Tran Minh Thanh", 1990},
        {1000, "Vo Quang Vinh", 1990},
        {1008, "Nguyen Van An", 1990}
    };

    cout << "Danh sach ban dau:\n";
    printStudents(students);

    // 9. Sắp xếp theo MSSV tăng dần
    sortByID(students);
    cout << "9. Danh sach sap xep theo MSSV tang dan:\n";
    printStudents(students);

    // Sắp xếp theo tên, nếu trùng tên thì theo năm sinh tăng dần
    sortByNameAndBirthYear(students);
    cout << "10. Danh sach sap xep theo ten va nam sinh:\n";
    printStudents(students);

    return 0;
}
