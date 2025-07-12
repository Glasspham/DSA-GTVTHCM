#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>

using namespace std;

class Store {
public:
    string id;
    string name;
    int yearFounded;
    int employees;
    double revenue2024;
    string operationTime; // "HC" hoặc "247"

    Store(string id, string name, int yearFounded, int employees, double revenue2024, string operationTime);
    void display() const;
};

#endif
