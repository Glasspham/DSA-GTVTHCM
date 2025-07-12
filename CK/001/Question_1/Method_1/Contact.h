#pragma once
#ifndef CONTACT_H
#define CONTACT_H
#include "iostream"
#include "string"
using namespace std;
class Contact {
private:
    string name;
    string phone;
    int group;
public:
    Contact() : name(""), phone(""), group(0) {}
    Contact(string name, string phone, int group) : name(name), phone(phone), group(group) {}
    void setName(string name) { this->name = name; }
    string getName() { return name; }
    void setPhone(string phone) { this->phone = phone; }
    string getPhone() { return phone; }
    void setGroup(int group) { this->group = group; }
    int getGroup() { return group; }
};
#endif // CONTRACT_H