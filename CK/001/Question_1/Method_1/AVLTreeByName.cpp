#include "AVLTreeByName.h"

// ----Private Functions---- //
Node* AVLTreeByName::insert(Node* node, Contact contact) {
    if (!node) return new Node(contact);
    if (contact.getName() < node->getData().getName())
        node->setLeft(insert(node->getLeft(), contact));
    else if (contact.getName() > node->getData().getName())
        node->setRight(insert(node->getRight(), contact));
    return balance(node);
}

Node* AVLTreeByName::search(Node* node, string name) {
    if (!node) return nullptr;
    if (name == node->getData().getName()) return node;
    if (name < node->getData().getName()) return search(node->getLeft(), name);
    return search(node->getRight(), name);
}

Node* AVLTreeByName::remove(Node* node, string name) {
    if (!node) return nullptr;
    if (name < node->getData().getName())
        node->setLeft(remove(node->getLeft(), name));
    else if (name > node->getData().getName())
        node->setRight(remove(node->getRight(), name));
    else {
        if (!node->getLeft()) {
            Node* temp = node->getRight();
            delete node;
            return temp;
        } else if (!node->getRight()) {
            Node* temp = node->getLeft();
            delete node;
            return temp;
        } else {
            Node* temp = getMin(node->getRight());
            node->setData(temp->getData());
            node->setRight(remove(node->getRight(), temp->getData().getName()));
        }
    }
    return balance(node);
}

Node* AVLTreeByName::getMin(Node* node) {
    while (node->getLeft()) node = node->getLeft();
    return node;
}

void AVLTreeByName::divideGroup() {
    groupMap.clear();
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        groupMap[node->getData().getGroup()].push_back(node->getData());
        if (node->getLeft()) q.push(node->getLeft());
        if (node->getRight()) q.push(node->getRight());
    }
}

// ----Public Functions---- //
void AVLTreeByName::insert(Contact contact) { root = insert(root, contact); }

Contact* AVLTreeByName::search(string name) {
    Node* node = search(root, name);
    return node ? &node->getData() : nullptr;
}

void AVLTreeByName::update(string name, Contact contact) {
    root = remove(root, name);
    root = insert(root, contact);
}

void AVLTreeByName::remove(string name) { root = remove(root, name); }

void AVLTreeByName::display() {
    divideGroup();
    for(int i = 1; i <= 4; i++) {
        cout << "Group ";
        if(i == 1) cout << "Family:" << endl;
        else if(i == 2) cout << "Company:" << endl;
        else if(i == 3) cout << "Friend" << endl;
        else cout << "Other:" << endl;
        bool flag = true;
        for (Contact contact : groupMap[i]) {
            cout << contact.getName() << " " << contact.getPhone() << endl;
            flag = false;
        }
        if (flag) cout << "Empty!" << endl;
    }
}