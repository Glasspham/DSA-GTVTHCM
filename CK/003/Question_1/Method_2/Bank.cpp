#include "Bank.h"

Bank::Bank() : root(nullptr) {}

Bank::~Bank() {}

int Bank::getHeight(Node* node) { return node ? node->height : 0; }

int Bank::getBalanceFactor(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Bank::Node* Bank::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Bank::Node* Bank::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Bank::Node* Bank::balance(Node* node) {
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1) {
        if (getBalanceFactor(node->left) < 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balanceFactor < -1) {
        if (getBalanceFactor(node->right) > 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
    /* int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) 
        return rotateRight(node);
    if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) 
        return rotateLeft(node);
    if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node; */
}

Bank::Node* Bank::insert(Node* node, Account* acc) {
    if (!node) return new Node(acc);
    if (acc->getAccNumber() < node->acc->getAccNumber())
        node->left = insert(node->left, acc);
    else if (acc->getAccNumber() > node->acc->getAccNumber())
        node->right = insert(node->right, acc);
    else return node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    return balance(node);
}

Bank::Node* Bank::search(Node* node, string accNumber) {
    if (!node) return nullptr;
    if (accNumber < node->acc->getAccNumber())
        return search(node->left, accNumber);
    if (accNumber > node->acc->getAccNumber())
        return search(node->right, accNumber);
    return node;
}

void Bank::insert(Account* acc) { root = insert(root, acc); }

Account* Bank::search(string accNumber) {
    Node* node = search(root, accNumber);
    return node ? node->acc : nullptr;
}

void Bank::depositMoney(string accNumber) {
    Account* acc = search(accNumber);
    if (!acc) {
        cout << "Tai khoan khong ton tai!\n";
        return;
    }
    if (acc->getStatus() == 1) {
        cout << "Tai khoan bi khoa!\n";
        return;
    }
    if (acc->getType() != "001") {
        cout << "Tai khoan khong phai la tai khoan thanh toan!\n";
        return;
    }
    int attempts = 0;
    string inputPass;
    while (attempts < 3) {
        cout << "Nhap mat khau: ";
        cin >> inputPass;
        if (inputPass == acc->getPassword()) break;
        attempts++;
        cout << "Sai mat khau! Con " << 3 - attempts << " lan nhap sai.\n";
    }
    if (attempts == 3) {
        cout << "Nhap sai qua 3 lan!. Tai khoan da bi khoa.\n";
        acc->block();
        return;
    }
    // Đọc số tiền từ file deposit.txt
    ifstream file("deposit.txt");
    double amount;
    if (file >> amount && amount > 0) {
        acc->deposit(amount);
        cout << "Nap tien thanh cong! So du tai khoan: " << acc->getBalance() << endl;
    } else {
        cout << "Loi khi doc so tien tu file\n";
    }
    file.close();
}

void Bank::checkAndUnblock(string accNumber) {
    Account* acc = search(accNumber);
    if (!acc) {
        cout << "Tai khoan khong ton tai!\n";
        return;
    }
    cout << "Tinh trang tai khoan: " << (acc->getStatus() == 0 ? "Active" : "Block") << endl;

    if (acc->getStatus() == 1) {
        char choice;
        cout << "Ban co muon mo khoa tai khoan? (Y/N): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            int attempts = 0;
            string inputPass;
            while (attempts < 3) {
                cout << "Nhap mat khau: ";
                cin >> inputPass;
                if (inputPass == acc->getPassword()) {
                    acc->unblock();
                    cout << "Tai khoan da duoc mo khoa thanh cong!\n";
                    break;
                }
                attempts++;
                cout << "Sai mat khau! Con " << 3 - attempts << " lan nhap sai.\n";
            }
            if (attempts == 3) {
                cout << "Nhap sai qua 3 lan!. Tai khoan van bi khoa.\n";
                acc->block();
                return;
            }
        } else {
            cout << "Tai khoan van bi khoa.\n";
        }
    }
}