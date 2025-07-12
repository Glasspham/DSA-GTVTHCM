#include "Polynomial.h"
#include <iostream>
using namespace std;

int main() {
    Polynomial poly1, poly2;

    // Nhập đa thức 1
    poly1.insertTerm(3, 2);
    poly1.insertTerm(5, 3);
    poly1.insertTerm(2, 0);
    cout << "Da thuc 1: ";
    poly1.printPolynomial();

    // Nhập đa thức 2
    poly2.insertTerm(4, 1);
    poly2.insertTerm(1, 0);
    cout << "Da thuc 2: ";
    poly2.printPolynomial();

    // Cộng hai đa thức
    Polynomial sum = poly1.addPolynomials(poly2);
    cout << "Tong hai da thuc: ";
    sum.printPolynomial();

    // Nhân hai đa thức
    Polynomial product = poly1.multiplyPolynomials(poly2);
    cout << "Tich hai da thuc: ";
    product.printPolynomial();

    // Tính giá trị đa thức tại x = 2
    int x = 2;
    cout << "Gia tri da thuc 1 tai x = " << x << " la: " << poly1.evaluatePolynomial(x) << endl;

    return 0;
}
