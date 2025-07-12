#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accNumber;
    string accName;
    string type; // 001: Thanh toan, 002: Tiet kiem
    double balance;
    int status; // 0: active, 1: block
    string password = "123456";
public:
    Account();
    Account(string, string, string, double, int);
    void setAccNumber(string);
    string getAccNumber();
    void setAccName(string);
    string getAccName();
    void setType(string);
    string getType();
    void setBalance(double);
    double getBalance();
    void setPassword(string);
    string getPassword();
    void deposit(double);
    void withdraw(double);
    int getStatus();
    void block();
    void unblock();
    ~Account();
};
#endif // ACCOUNT_H