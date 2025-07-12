#include "Polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;

Polynomial::Polynomial() { head = nullptr; }

Polynomial::~Polynomial() {
    Term* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void Polynomial::insertTerm(int coeff, int exp) {
    if (coeff == 0) return; // Bỏ qua hệ số 0
    Term* newNode = new Term(coeff, exp);
    // Trường hợp danh sách rỗng hoặc chèn vào đầu
    if (!head || head->exp < exp) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Term* temp = head;
    Term* prev = nullptr;
    while (temp && temp->exp > exp) {
        prev = temp;
        temp = temp->next;
    }
    // Nếu tìm thấy số mũ trùng
    if (temp && temp->exp == exp) {
        temp->coeff += coeff;
        if (temp->coeff == 0) { // Nếu hệ số bằng 0, xóa node
            if (prev) prev->next = temp->next;
            else head = temp->next;
            delete temp;
        }
        return;
    }
    // Chèn node mới vào đúng vị trí
    newNode->next = temp;
    if (prev) prev->next = newNode;
}

void Polynomial::printPolynomial() {
    if (!head) {
        cout << "0" << endl;
        return;
    }
    Term* temp = head;
    while (temp) {
        cout << temp->coeff;
        if(temp->exp == 1) cout << "x";
        else if(temp->exp != 0) cout << "x^" << temp->exp;
        if (temp->next) cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

int Polynomial::evaluatePolynomial(int x) {
    int result = 0;
    Term* temp = head;
    while (temp) {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    }
    return result;
}

Polynomial Polynomial::addPolynomials(const Polynomial& other) {
    Polynomial result;
    Term* p1 = head;
    Term* p2 = other.head;
    while (p1) {
        result.insertTerm(p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2) {
        result.insertTerm(p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}

Polynomial Polynomial::multiplyPolynomials(const Polynomial& other) {
    Polynomial result;
    for (Term* i = head; i; i = i->next)
        for (Term* j = other.head; j; j = j->next)
            result.insertTerm(i->coeff * j->coeff, i->exp + j->exp);
    return result;
}
