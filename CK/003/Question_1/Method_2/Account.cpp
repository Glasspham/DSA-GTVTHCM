#include "Account.h"

Account::Account(): accNumber(""), accName(""), type(""), balance(0), status(0) {}

Account::Account(string accNumber, string accName, string type, double balance, int status) :
    accNumber(accNumber), accName(accName), type(type), balance(balance), status(status) {}

void Account::setAccNumber(string accNumber) { this->accNumber = accNumber; }

string Account::getAccNumber() { return accNumber; }

void Account::setAccName(string accName) { this->accName = accName; }

string Account::getAccName() { return accName; }

void Account::setType(string type) { this->type = type; }

string Account::getType() { return type; }

void Account::setBalance(double balance) { this->balance = balance; }

double Account::getBalance() { return balance; }

void Account::setPassword(string password) { this->password = password; }

string Account::getPassword() { return password; }

void Account::deposit(double amount) { balance += amount; }

void Account::withdraw(double amount) { balance -= amount; }

int Account::getStatus() { return status; }

void Account::block() { status = 1; }

void Account::unblock() { status = 0; }

Account::~Account() {}