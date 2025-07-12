#include "AVL_tree.h"

int AVL_tree::getHeight(Node* p) {
    if (p == nullptr) return 0;
    return p->getHeight();
}

int AVL_tree::checkBalance(Node* p) {
    if (p == nullptr) return 0;
    return getHeight(p->getLeft()) - getHeight(p->getRight());
}

void AVL_tree::rotateLeft(Node*& x) {
    Node* y = x->getRight();
    Node* T2 = y->getLeft();
    y->setLeft(x);
    x->setRight(T2);
    x->setHeight(1 + max(getHeight(x->getLeft()), getHeight(x->getRight())));
    y->setHeight(1 + max(getHeight(y->getLeft()), getHeight(y->getRight())));
    x = y;
}

void AVL_tree::rotateRight(Node*& y) {
    Node* x = y->getLeft();
    Node* T2 = x->getRight();
    x->setRight(y);
    y->setLeft(T2);
    y->setHeight(1 + max(getHeight(y->getLeft()), getHeight(y->getRight())));
    x->setHeight(1 + max(getHeight(x->getLeft()), getHeight(x->getRight())));
    y = x;
}

Node* AVL_tree::deleteNode(Node* root, string key) {
    if (!root) return root;
    if (key < root->getKey().getWordEnglish()) 
        root->setLeft(deleteNode(root->getLeft(), key));
    else if (key > root->getKey().getWordEnglish()) 
        root->setRight(deleteNode(root->getRight(), key));
    else {
        if (!root->getLeft() || !root->getRight()) {
            Node* temp = root->getLeft() ? root->getLeft() : root->getRight();
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else *root = *temp;
            delete temp;
        }
        else {
            Node* temp = root->getRight();
            while (temp->getLeft()) temp = temp->getLeft();
            root->setKey(temp->getKey());
            root->setRight(deleteNode(root->getRight(), temp->getKey().getWordEnglish()));
        }
    }
    if (root == nullptr) return root;
    root->setHeight(1 + max(getHeight(root->getLeft()), getHeight(root->getRight())));
    int balance = checkBalance(root);
    if (balance > 1 && checkBalance(root->getLeft()) >= 0)
        rotateRight(root);
    if (balance > 1 && checkBalance(root->getLeft()) < 0) {
        Node* nLeft = root->getLeft();
        rotateLeft(nLeft);
        root->setLeft(nLeft);
        rotateRight(root);
    }
    if (balance < -1 && checkBalance(root->getRight()) <= 0)
        rotateLeft(root);
    if (balance < -1 && checkBalance(root->getRight()) > 0) {
        Node* nRight = root->getRight();
        rotateRight(nRight);
        root->setRight(nRight);
        rotateLeft(root);
    }
    return root;
}

Node* AVL_tree::insert(Node* node, Word word) {
    if (node == nullptr) return new Node(word);
    if (word < node->getKey()) node->setLeft(insert(node->getLeft(), word));
    else if (word > node->getKey()) node->setRight(insert(node->getRight(), word));
    else return node;
    node->setHeight(1 + max(getHeight(node->getLeft()), getHeight(node->getRight())));
    int balance = checkBalance(node);
    if (balance > 1 && word < node->getLeft()->getKey())
        rotateRight(node);
    if (balance < -1 && word > node->getRight()->getKey())
        rotateLeft(node);
    if (balance > 1 && word > node->getLeft()->getKey()) {
        Node* nLeft = node->getLeft();
        rotateLeft(nLeft);
        node->setLeft(nLeft);
        rotateRight(node);
    }
    if (balance < -1 && word < node->getRight()->getKey()) {
        Node* nRight = node->getRight();
        rotateRight(nRight);
        node->setRight(nRight);
        rotateLeft(node);
    }
    return node;
}

Node* AVL_tree::search(Node* root, string key) {
    if (!root) return nullptr;
    if (key == root->getKey().getWordEnglish()) return root;
    if (key < root->getKey().getWordEnglish()) return search(root->getLeft(), key);
    return search(root->getRight(), key);
}


void AVL_tree::insert(Word word) {
    root = insert(root, word);
}

void AVL_tree::deleteNode(string key) {
    root = deleteNode(root, key);
}

bool AVL_tree::search(string key, string& res) {
    Node *result = search(root, key);
    if (result) {
        res = result->getKey().getWordVietnamese();
        return true;
    }
    return false;
}

bool AVL_tree::modify(string english, string vietnamese) {
    Node* node = search(root, english);
    if (node != nullptr) {
        Word modifiedWord = node->getKey();
        modifiedWord.setWordVietnamese(vietnamese);
        node->setKey(modifiedWord);
        return true;
    }
    return false;
}

void AVL_tree::LNR(Node* root) {
    if (!root) return;
    LNR(root->getLeft());
    cout << "English: " << root->getKey().getWordEnglish() << " -> Vietnamese: " << root->getKey().getWordVietnamese() << endl;
    LNR(root->getRight());
}

void AVL_tree::TravelLNR() { 
    LNR(root); 
}