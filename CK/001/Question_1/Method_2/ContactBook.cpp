#include "ContactBook.h"

// --- Helper functions ---
bool isPhone(string key) {
    for(char c : key)
        if (!isdigit(c)) return false;
    return true;
}

// --- ContactBook methods ---
void ContactBook::addContact(string name, string phone, int group)  {
    if(search(name)) {
        cout << "Name already exists" << endl;
        return;
    }
    if(search(phone)) {
        cout << "Phone already exists" << endl;
        return;
    }
    Contact contact(name, phone, group);
    treeByName.insert(contact, [](Contact c) { return c.getName(); });
    treeByPhone.insert(contact, [](Contact c) { return c.getPhone(); });
}

Contact* ContactBook::search(string key) {
    if(isPhone(key)) return treeByPhone.search(key, [](Contact c) { return c.getPhone(); });
    return treeByName.search(key, [](Contact c) { return c.getName(); });
}

void ContactBook::removeContact(string key) {
    Contact* contact = search(key);
    if (contact) {
        if (isPhone(key)) {
            treeByPhone.remove(key, [](Contact c) { return c.getPhone(); });
            treeByName.remove(contact->getName(), [](Contact c) { return c.getName(); });
        } else {
            treeByName.remove(key, [](Contact c) { return c.getName(); });
            treeByPhone.remove(contact->getPhone(), [](Contact c) { return c.getPhone(); });
        }
    } else cout << "Can't find contact" << endl;
}

void ContactBook::updateContact(string key, string newName, string newPhone, int newGroup) {
    Contact* contact = search(key);
    if (!contact) {
        cout << "Can't find contact" << endl;
        return;
    }
    if (newName != contact->getName() && search(newName)) {
        cout << "Name already exists" << endl;
        return;
    }
    if (newPhone != contact->getPhone() && search(newPhone)) {
        cout << "Phone already exists" << endl;
        return;
    }
    removeContact(key);
    addContact(newName, newPhone, newGroup);
}   

void ContactBook::displayContacts() { treeByName.display(); }