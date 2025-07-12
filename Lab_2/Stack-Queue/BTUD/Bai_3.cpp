#if 0 // ! Thư viện Queue
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Hàm kiểm tra xem có thể đạt được thứ tự mong muốn tại C hay không
bool solveRailwayReordering(int n, vector<int>& targetOrder) {
    queue<int> A;  // Hàng đợi chứa các toa ban đầu
    queue<int> B;  // Hàng đợi trung gian
    queue<int> C;  // Kết quả mong muốn
    // Đưa các toa tàu vào hàng đợi A (theo thứ tự ban đầu)
    for (int i = 1; i <= n; i++) A.push(i);
    int targetIndex = 0;  // Chỉ số của toa tàu mong muốn tại C
    vector<string> steps;
    while (!A.empty() || !B.empty()) {
        // Nếu B có toa tàu đúng thứ tự, chuyển sang C
        if (!B.empty() && B.front() == targetOrder[targetIndex]) {
            C.push(B.front());
            B.pop();
            steps.push_back("B->C");
            targetIndex++;
        }
        // Nếu A có toa tàu đúng thứ tự, chuyển sang C
        else if (!A.empty() && A.front() == targetOrder[targetIndex]) {
            C.push(A.front());
            A.pop();
            steps.push_back("A->C");
            targetIndex++;
        }
        // Nếu không, lấy từ A đưa vào B
        else if (!A.empty()) {
            B.push(A.front());
            A.pop();
            steps.push_back("A->B");
        }
        // Nếu không có cách nào hợp lệ, dừng lại
        else {
            cout << "Khong the sap xep theo thu tu mong muon!\n";
            return false;
        }
    }
    // In ra các bước di chuyển
    cout << "Co the sap xep! Cac buoc di chuyen la:\n";
    for (const string& step : steps)
        cout << step << endl;
    return true;
}

int main() {
    cout << "Nhap so toa tau: ";
    int n; cin >> n;
    vector<int> targetOrder(n);
    cout << "Nhap thu tu mong muon tai C: ";
    for (int i = 0; i < n; i++)
        cin >> targetOrder[i];
    solveRailwayReordering(n, targetOrder);
    return 0;
}
#endif

#if 1 // ! Tự viết Queue
#include <iostream>
#include <vector>

using namespace std;

// Tự cài đặt hàng đợi (queue)
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* frontNode;
    Node<T>* rearNode;
    int size;
public:
    Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

    bool empty() { return size == 0; }

    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (rearNode) rearNode->next = newNode;
        rearNode = newNode;
        if (!frontNode) frontNode = newNode;
        size++;
    }

    void pop() {
        if (empty()) return;
        Node<T>* temp = frontNode;
        frontNode = frontNode->next;
        if (!frontNode) rearNode = nullptr;
        delete temp;
        size--;
    }

    T front() {
        if (!empty()) return frontNode->data;
        throw runtime_error("Queue is empty");
    }
};

// Hàm kiểm tra xem có thể đạt được thứ tự mong muốn tại C hay không
bool solveRailwayReordering(int n, vector<int>& targetOrder) {
    Queue<int> A, B, C;
    for (int i = 1; i <= n; i++) A.push(i);
    int targetIndex = 0;
    vector<string> steps;
    while (!A.empty() || !B.empty()) {
        if (!B.empty() && B.front() == targetOrder[targetIndex]) {
            C.push(B.front()); B.pop();
            steps.push_back("B->C");
            targetIndex++;
        }
        else if (!A.empty() && A.front() == targetOrder[targetIndex]) {
            C.push(A.front()); A.pop();
            steps.push_back("A->C");
            targetIndex++;
        }
        else if (!A.empty()) {
            B.push(A.front()); A.pop();
            steps.push_back("A->B");
        }
        else {
            cout << "Khong the sap xep theo thu tu mong muon!\n";
            return false;
        }
    }
    cout << "Co the sap xep! Cac buoc di chuyen la:\n";
    for (const string& step : steps)
        cout << step << endl;
    return true;
}

int main() {
    cout << "Nhap so toa tau: ";
    int n; cin >> n;
    vector<int> targetOrder(n);
    cout << "Nhap thu tu mong muon tai C: ";
    for (int i = 0; i < n; i++) cin >> targetOrder[i];
    solveRailwayReordering(n, targetOrder);
    return 0;
}
#endif