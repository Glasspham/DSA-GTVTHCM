#if 0 // ! Thư viện Stack
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Hàm kiểm tra xem có thể đạt được thứ tự mong muốn tại C hay không
bool solveRailwayShunting(int n, vector<int>& targetOrder) {
    stack<int> A, B, C;
    // Đưa tất cả các toa tàu vào A (theo thứ tự ban đầu)
    for (int i = n; i >= 1; i--) A.push(i);
    int targetIndex = 0;  // Chỉ số của toa tàu mong muốn tại C
    vector<string> steps;
    while (!A.empty() || !B.empty()) {
        // Nếu B có toa tàu đúng thứ tự, chuyển sang C
        if (!B.empty() && B.top() == targetOrder[targetIndex]) {
            C.push(B.top());
            B.pop();
            steps.push_back("B->C");
            targetIndex++;
        }
        // Nếu A có toa tàu đúng thứ tự, chuyển sang C
        else if (!A.empty() && A.top() == targetOrder[targetIndex]) {
            C.push(A.top());
            A.pop();
            steps.push_back("A->C");
            targetIndex++;
        }
        // Nếu không, lấy từ A đưa vào B
        else if (!A.empty()) {
            B.push(A.top());
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
    for (int i = 0; i < n; i++) cin >> targetOrder[i];
    solveRailwayShunting(n, targetOrder);
    return 0;
}
#endif

#if 1 // ! Tự viết Stack
#include <iostream>
#include <vector>

using namespace std;

// Tự cài đặt ngăn xếp (stack)
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* topNode;
    int size;
public:
    Stack() : topNode(nullptr), size(0) {}

    bool empty() { return size == 0; }

    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }

    void pop() {
        if (empty()) return;
        Node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
        size--;
    }

    T top() {
        if (!empty()) return topNode->data;
        throw runtime_error("Stack is empty");
    }
};

// Hàm kiểm tra xem có thể đạt được thứ tự mong muốn tại C hay không
bool solveRailwayShunting(int n, vector<int>& targetOrder) {
    Stack<int> A, B, C;
    for (int i = n; i >= 1; i--) A.push(i);
    int targetIndex = 0;
    vector<string> steps;
    while (!A.empty() || !B.empty()) {
        if (!B.empty() && B.top() == targetOrder[targetIndex]) {
            C.push(B.top()); B.pop();
            steps.push_back("B->C");
            targetIndex++;
        }
        else if (!A.empty() && A.top() == targetOrder[targetIndex]) {
            C.push(A.top()); A.pop();
            steps.push_back("A->C");
            targetIndex++;
        }
        else if (!A.empty()) {
            B.push(A.top()); A.pop();
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
    solveRailwayShunting(n, targetOrder);
    return 0;
}
#endif