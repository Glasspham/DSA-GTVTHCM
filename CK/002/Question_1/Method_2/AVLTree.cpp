#include "AVLTree.h"

// --- AVLNode Constructor ---
AVLNode::AVLNode(Store* store) : store(store), left(nullptr), right(nullptr), height(1) {}

// --- AVLTree Constructor ---
AVLTree::AVLTree() : root(nullptr) {}

// --- Get height ---
int AVLTree::getHeight(AVLNode* node) { return node ? node->height : 0; }

// --- Get balance factor ---
int AVLTree::getBalanceFactor(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// --- Rotate Right ---
AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

// --- Rotate Left ---
AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

// --- Balance the tree ---
AVLNode* AVLTree::balance(AVLNode* node) {
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
}

// --- Insert a store ---
AVLNode* AVLTree::insert(AVLNode* node, Store* store) {
    if (!node) return new AVLNode(store);
    if (store->id < node->store->id)
        node->left = insert(node->left, store);
    else if (store->id > node->store->id)
        node->right = insert(node->right, store);
    else return node; // Không chèn trùng lặp
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    return balance(node);
}

void AVLTree::insert(Store* store) { root = insert(root, store); }

// --- Inorder Traversal ---
void AVLTree::inOrder(AVLNode* node) {
    if (!node) return;
    inOrder(node->left);
    node->store->display();
    inOrder(node->right);
}

void AVLTree::inOrder() { inOrder(root); }

// --- Remove ---
AVLNode* AVLTree::remove(AVLNode* node, string id) {
    if (!node) return node;
    if (id < node->store->id)
        node->left = remove(node->left, id);
    else if (id > node->store->id)
        node->right = remove(node->right, id);
    else {
        if (!node->left) {
            AVLNode *tmp = node->right;
            delete node;
            return tmp;
        } else if (!node->right) {
            AVLNode *tmp = node->left;
            delete node;
            return tmp;
        } else {
            AVLNode* temp = minValueNode(node->right);
            node->store = temp->store;
            node->right = remove(node->right, temp->store->id);
        }
    }
    return balance(node);
}

void AVLTree::remove(string id) { root = remove(root, id); }

// --- Min Value Node ---
AVLNode* AVLTree::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// --- a. Liệt kê cửa hàng có số nhân viên > bao nhiêu
void AVLTree::listStoresWithEmployeesGreaterThan(AVLNode* node, int minEmployees) {
    if (!node) return;
    listStoresWithEmployeesGreaterThan(node->left, minEmployees);
    if (node->store->employees > minEmployees)
        node->store->display();
    listStoresWithEmployeesGreaterThan(node->right, minEmployees);
}

void AVLTree::listStoresWithEmployeesGreaterThan(int minEmployees) {
    listStoresWithEmployeesGreaterThan(root, minEmployees);
}

// --- b. Xóa cửa hàng đã hoạt động trên 5 năm và doanh thu < 200 triệu
AVLNode* AVLTree::removeOldLowRevenueStores(AVLNode* node, int year, int currentYear, int revenue) {
    if (!node) return nullptr;
    node->left = removeOldLowRevenueStores(node->left, year, currentYear, revenue);
    node->right = removeOldLowRevenueStores(node->right, year, currentYear, revenue);
    /* if (currentYear - node->store->yearFounded > year && node->store->revenue2024 < revenue) {
        AVLNode* temp = node;
        node = remove(node, temp->store->id);
        delete temp;
    } */
    if (currentYear - node->store->yearFounded > year && node->store->revenue2024 < revenue) {
        AVLNode* newRoot = remove(node, node->store->id); // Xóa node và cập nhật gốc mới
        return newRoot; // Trả về node gốc mới của cây con sau khi xóa
    }
    return node;
}

void AVLTree::removeOldLowRevenueStores(int year, int currentYear, int revenue) {
    root = removeOldLowRevenueStores(root, year, currentYear, revenue);
}

// --- c. Tính trung bình doanh thu theo loại hình hoạt động
void AVLTree::averageRevenueByOperationTime(AVLNode* node, string operationTime, double& totalRevenue, int& count) {
    if (!node) return;
    averageRevenueByOperationTime(node->left, operationTime, totalRevenue, count);
    if (node->store->operationTime == operationTime) {
        totalRevenue += node->store->revenue2024;
        count++;
    }
    averageRevenueByOperationTime(node->right, operationTime, totalRevenue, count);
}

double AVLTree::averageRevenueByOperationTime(string operationTime) {
    int count = 0;
    double totalRevenue = 0.0;
    averageRevenueByOperationTime(root, operationTime, totalRevenue, count);
    return (count == 0) ? 0.0 : totalRevenue / count;
}