// ! Tự viết hàm sort theo các giải thuật sắp xếp
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// Hàm in mảng
void PrintArray(int a[], int N) {
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << endl;
}

// 1. Sắp xếp tăng dần
void SortAscending(int a[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
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
    for (int i = 0; i < N - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < N; j++)
            if (abs(a[j]) < abs(a[minIdx]))
                minIdx = j;
        swap(a[i], a[minIdx]);
    }
}

// 5. Sắp xếp số dương giảm dần, số âm tăng dần
void SortPositiveNegative(int a[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++)
            if (a[j] < a[j + 1])
                swap(a[j], a[j + 1]);
    }
    int index = -1;
    for (int i = 0; i < N; i++) {
        if (a[i] < 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < N - 1; i++) {
            for (int j = index; j < N - (i - index) - 1; j++)
                if (a[j] > a[j + 1]) 
                    swap(a[j], a[j + 1]);
        }
    }
}

// 6. Chẵn tăng dần, lẻ giảm dần
void SortEvenOdd(int a[], int N) {
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] % 2 == 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    SortAscending(a, j);
    for (int i = j; i < N - 1; i++) {
        for (int k = j; k < N - (i - j) - 1; k++)
            if (a[k] < a[k + 1])
                swap(a[k], a[k + 1]);
    }
}

// 7. Sắp xếp theo vị trí chẵn/lẻ ban đầu
void SortEvenOddStable(int a[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((a[i] % 2 == 0 && a[j] % 2 == 0 && a[i] > a[j]) || 
                (a[i] % 2 != 0 && a[j] % 2 != 0 && a[i] < a[j])) {
                swap(a[i], a[j]);
            }
        }
    }
}

// 8. Tạo một cấu trúc dữ liệu để xử lý danh sách trên.
class Student {
private:
    int id;
    string name;
    int birthYear;

public:
    // Constructor
    Student(int id, string name, int birthYear) : id(id), name(name), birthYear(birthYear) {}

    void printStudent() const {
        cout << id << "\t" << name << "\t\t" << birthYear << endl;
    }

    // Hàm hiển thị danh sách sinh viên
    static void printStudents(const Student students[], int n) {
        cout << "MSSV\tHo va ten\t\tNam sinh\n";
        for (int i = 0; i < n; ++i) {
            students[i].printStudent();
        }
        cout << "------------------------------------------------\n";
    }

    // 9. Hàm sắp xếp danh sách theo MSSV tăng dần
    static void sortByID(Student students[], int n) {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (students[j].id > students[j + 1].id)
                    swap(students[j], students[j + 1]);
    }

    // 10. Hàm sắp xếp danh sách theo tên (thứ tự bảng chữ cái), nếu trùng thì theo năm sinh tăng dần
    static void sortByNameAndYear(Student students[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                string lastWord1 = getLastWord(students[j].name);
                string lastWord2 = getLastWord(students[j + 1].name);
                if (lastWord1 > lastWord2 || 
                    (lastWord1 == lastWord2 && students[j].birthYear > students[j + 1].birthYear)) {
                    swap(students[j], students[j + 1]);
                }
            }
        }
    }

    static void swap(Student& a, Student& b) {
        Student temp = a;
        a = b;
        b = temp;
    }

    static string getLastWord(const string& str) {
        istringstream iss(str);
        string word, lastWord;
        while (iss >> word) lastWord = word;
        return lastWord;
    }

    int getID() const { return id; }
};

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
    Student students[] = {
        Student(1005, "Tran Minh Thanh", 1991),
        Student(1001, "Tran Thi Bich", 1988),
        Student(1003, "Tran Minh Thanh", 1990),
        Student(1000, "Vo Quang Vinh", 1990),
        Student(1008, "Nguyen Van An", 1990)
    };
    int n = sizeof(students) / sizeof(students[0]);

    cout << "Danh sach ban dau:\n";
    Student::printStudents(students, n);

    // 9. Sắp xếp theo MSSV tăng dần
    Student::sortByID(students, n);
    cout << "9. Danh sach sap xep theo MSSV tang dan:\n";
    Student::printStudents(students, n);

    // 10. Sắp xếp theo tên, nếu trùng tên thì theo năm sinh tăng dần
    Student::sortByNameAndYear(students, n);
    cout << "10. Danh sach sap xep theo ten va nam sinh:\n";
    Student::printStudents(students, n);

    return 0;
}
