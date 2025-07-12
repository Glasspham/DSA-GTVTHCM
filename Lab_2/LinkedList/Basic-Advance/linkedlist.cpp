#include "linkedlist.h"
#include <iostream>
using namespace std;

linkedlist::linkedlist() {
    // ctor
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}

linkedlist::~linkedlist() {}

void linkedlist::InsertFirst(element *e) {
    if (this->head == nullptr)
        this->head = this->tail = e;
    else {
        e->Setpointer(this->head); // step 1
        this->head = e;            // step 2
    }
    this->nNum++;
}

void linkedlist::InsertTail(element *e) {
    if (this->head == nullptr)
    this->head = this->tail = e;
    else {
        this->tail->Setpointer(e); // step 1
        this->tail = e;            // step 2
    }
    this->nNum++;
}

void linkedlist::InsertFirstUnique(element *e) {
    element *p = head;
    while (p != nullptr) {
        if (p->Getdata() == e->Getdata()) {
            cout << "Element already exists!\n";
            return;
        }
        p = p->Getpointer();
    }
    InsertFirst(e);
}

void linkedlist::InsertTailUnique(element *e) {
    element *p = head;
    while (p != nullptr) {
        if (p->Getdata() == e->Getdata()) {
            cout << "Element already exists!\n";
            return;
        }
        p = p->Getpointer();
    }
    InsertTail(e);
}

void linkedlist::insertAfter(element *e, element *p) {
    element *tmp = this->head;
    while (tmp != nullptr) {
        if (tmp->Getdata() == e->Getdata()) {
            p->Setpointer(tmp->Getpointer());
            tmp->Setpointer(p);
            nNum++;
            return;
        }
        tmp = tmp->Getpointer();
    }
}

bool linkedlist::DeleteFirst() {
    if (this->head == nullptr)
        return false;
    else {
        element *p = this->head;
        this->head = this->head->Getpointer();
        delete p;
        --nNum;
        return true;
    }
}

bool linkedlist::DeleteLast() {
    if (this->head == nullptr)
        return false;
    if (this->head == this->tail) { // Nếu chỉ có 1 phần tử
        delete this->head;
        this->head = this->tail = nullptr;
        nNum = 0;
        return true;
    }
    element *p = this->head;
    while (p->Getpointer() != this->tail)
        p = p->Getpointer();
    delete this->tail;
    this->tail = p;
    this->tail->Setpointer(nullptr); // Đặt con trỏ tail về nullptr
    nNum--;
    return true;
}

bool linkedlist::DeleteAfter(element *e) {
    element *p = this->head;
    while (p != nullptr) {
        if (p->Getdata() == e->Getdata()) {
            element *temp = p->Getpointer();
            p->Setpointer(temp->Getpointer());
            delete temp;
            --nNum;
            return true;
        }
        p = p->Getpointer();
    }
    return false;
}

void linkedlist::RemoveAll() {
    element *p = head;
    while (p != nullptr) {
        element *temp = p;
        p = p->Getpointer(); // Di chuyển đến phần tử kế tiếp
        delete temp;         // Xóa phần tử hiện tại
    }
    head = tail = nullptr; // Đặt danh sách về rỗng
    nNum = 0;
}

void linkedlist::Travel() {
    element *p = this->head;
    while (p != nullptr)
    {
        cout << p->Getdata() << "\t";
        p = p->Getpointer();
    }
}

int linkedlist::SumList() {
    int sum = 0;
    element* p = head;
    while (p != nullptr) {
        sum += p->Getdata();  // Cộng giá trị của từng phần tử vào tổng
        p = p->Getpointer();  // Di chuyển đến phần tử kế tiếp
    }
    return sum;
}

int linkedlist::MaxList() {
    if (head == nullptr) {
        cout << "List Empty!\n";
        return -1; // Trả về giá trị nhỏ nhất nếu danh sách rỗng
    }
    
    int maxVal = head->Getdata(); // Giả sử phần tử đầu tiên là lớn nhất
    element* p = head->Getpointer();
    
    while (p != nullptr) {
        if (p->Getdata() > maxVal) {
            maxVal = p->Getdata(); // Cập nhật giá trị lớn nhất
        }
        p = p->Getpointer(); // Di chuyển đến phần tử tiếp theo
    }
    
    return maxVal;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int linkedlist::CountPrime() {
    int count = 0;
    element* p = head;
    
    while (p != nullptr) {
        if (isPrime(p->Getdata())) {
            count++; // Tăng biến đếm nếu số hiện tại là số nguyên tố
        }
        p = p->Getpointer(); // Di chuyển đến phần tử kế tiếp
    }
    
    return count;
}

int linkedlist::CountX(int x) {
    int count = 0;
    element* p = this->head;
    while (p != nullptr) {
        if (p->Getdata() == x) 
            count++;
        p = p->Getpointer();
    }
    return count;
}

void linkedlist::splitList(int x, linkedlist &lessList, linkedlist &greaterList) {
    element *p = this->head;
    while (p != nullptr) {
        element *newNode = new element(p->Getdata());
        if (p->Getdata() < x) lessList.InsertTail(newNode);
        else greaterList.InsertTail(newNode);
        p = p->Getpointer();
    }
}
