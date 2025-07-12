#pragma once
#ifndef BANK_MANAGEMENT_H
#define BANK_MANAGEMENT_H
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "BankAccount.h"
class BankManagement {
private:
    vector<BankAccount> accounts;

public:
    void addAccount(BankAccount account);
    bool deposit(string accountNumber);
    void checkStatus(string accountNumber);
};
#endif