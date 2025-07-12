#include <iostream>
using namespace std;

// Cấu trúc một phần tử của danh sách liên kết
class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Lớp danh sách liên kết
class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Thêm phần tử vào đầu danh sách (dùng cho Stack)
    void insertFirst(int x) {
        Node* newNode = new Node(x);
        if (!head) tail = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Thêm phần tử vào cuối danh sách (dùng cho Queue)
    void insertLast(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Xóa phần tử đầu danh sách (dùng cho Stack & Queue)
    int deleteFirst() {
        if (!head) return -1; // Danh sách rỗng
        Node* temp = head;
        int value = temp->data;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
        return value;
    }

    // Xóa phần tử cuối danh sách (dùng cho Queue)
    int deleteLast() {
        if (!head) return -1; // Danh sách rỗng
        if (head == tail) { // Nếu chỉ có 1 phần tử
            int value = head->data;
            delete head;
            head = tail = nullptr;
            return value;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        int value = tail->data;
        delete tail;
        tail = temp;
        tail->next = nullptr;
        return value;
    }

    // In danh sách
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty() { return head == nullptr; }
};

// Lớp Stack (Ngăn xếp)
class Stack {
private:
    LinkedList list;
public:
    void push(int x) { list.insertFirst(x); }
    
    int pop() {
        int value = list.deleteFirst();
        if (value == -1) cout << "STACK RONG, KHONG LAY DUOC PHAN TU" << endl;
        return value;
    }
    
    void printStack() { list.printList(); }
};

// Lớp Queue (Hàng đợi)
class Queue {
private:
    LinkedList list;
public:
    void enqueue(int x) { list.insertLast(x); }
    
    int dequeue() {
        int value = list.deleteFirst();
        if (value == -1) cout << "QUEUE RONG, KHONG LAY DUOC PHAN TU" << endl;
        return value;
    }
    
    void printQueue() { list.printList(); }
};

// Hàm main để kiểm tra chương trình
int main() {
    Stack stack;
    Queue queue;
    
    cout << "Nhap 3 gia tri vao Stack: ";
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        stack.push(x);
    }
    
    cout << "Stack sau khi them: ";
    stack.printStack();

    cout << "Pop 4 lan tu Stack:\n";
    for (int i = 0; i < 4; i++) {
        int value = stack.pop();
        if (value != -1) cout << "Lay ra: " << value << endl;
    }
    
    cout << "Nhap 3 gia tri vao Queue: ";
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        queue.enqueue(x);
    }

    cout << "Queue sau khi them: ";
    queue.printQueue();

    cout << "Dequeue 4 lan tu Queue:\n";
    for (int i = 0; i < 4; i++) {
        int value = queue.dequeue();
        if (value != -1) cout << "Lay ra: " << value << endl;
    }

    return 0;
}
