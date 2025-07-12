#include <iostream>
using namespace std;

#if 0 // Câu 1
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

    // Thêm phần tử vào cuối danh sách (Insert Tail)
    void insertTail(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Xóa phần tử cuối danh sách (Delete Tail)
    int deleteTail() {
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

    // Xóa phần tử đầu danh sách (Delete Head)
    int deleteHead() {
        if (!head) return -1;
        Node* temp = head;
        int value = temp->data;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
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

// Lớp Stack (Ngăn xếp) - Cài đặt với InsertTail & DeleteTail
class Stack {
private:
    LinkedList list;
public:
    void push(int x) { list.insertTail(x); }
    
    int pop() {
        int value = list.deleteTail();
        if (value == -1) cout << "STACK RONG, KHONG LAY DUOC PHAN TU" << endl;
        return value;
    }
    
    void printStack() { list.printList(); }
};

// Lớp Queue (Hàng đợi) - Cài đặt với InsertTail & DeleteHead
class Queue {
private:
    LinkedList list;
public:
    void enqueue(int x) { list.insertTail(x); }
    
    int dequeue() {
        int value = list.deleteHead();
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
#endif

#if 0 // Câu 3
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}
    
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    
    void pop() {
        if (isEmpty()) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    
    int peek() {
        if (isEmpty()) throw runtime_error("Stack is empty");
        return top->data;
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
};

void convertToBinary(int num) {
    Stack stack;
    if (num == 0) {
        cout << "0";
        return;
    }
    
    while (num > 0) {
        stack.push(num % 2);
        num /= 2;
    }
    
    while (!stack.isEmpty()) {
        cout << stack.peek();
        stack.pop();
    }
    cout << endl;
}

int main() {
    cout << "Nhap so can chuyen doi: ";
    int num; cin >> num;
    cout << "So nhi phan: ";
    convertToBinary(num);
    return 0;
}
#endif