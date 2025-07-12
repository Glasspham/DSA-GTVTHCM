#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string name;
    string phone;
    int group; // 1-Gia đình, 2-Công ty, 3-Bạn, 4-Khác
public:
    Contact() : name(""), phone(""), group(4) {}
    Contact(string n, string p, int g) : name(n), phone(p), group(g) {}
    void setName(string n) { name = n; }
    string getName() const { return name; }
    void setPhone(string p) { phone = p; }
    string getPhone() const { return phone; }
    void setGroup(int g) { group = g; }
    int getGroup() const { return group; }
    void display() const { cout << "Name: " << name << ", Phone: " << phone << endl; }
    bool operator<(const Contact &other) const { return name < other.name; }
    bool operator>(const Contact &other) const { return name > other.name; }
    bool operator==(const Contact &other) const { return name == other.name; }
};

#endif // CONTACT_H
