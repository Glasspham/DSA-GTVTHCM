#pragma once
#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

class Term {
public:
    int coeff;  // Hệ số
    int exp;    // Số mũ
    Term* next;

    Term(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};

class Polynomial {
private:
    Term* head;

public:
    Polynomial();
    ~Polynomial();
    void insertTerm(int coeff, int exp);
    void printPolynomial();
    int evaluatePolynomial(int x);
    Polynomial addPolynomials(const Polynomial& p);  // Sửa lại dùng tham chiếu
    Polynomial multiplyPolynomials(const Polynomial& p);
};

#endif //_POLYNOMIAL_H_
