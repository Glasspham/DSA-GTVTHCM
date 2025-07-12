#pragma once
#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include "AVLTree.h"
#include "Contact.h"

class ContactBook {
private:
    AVLTree<Contact, string> treeByName;
    AVLTree<Contact, string> treeByPhone;
public:
    void addContact(string name, string phone, int group);
    Contact* search(string key);
    void removeContact(string key);
    void updateContact(string key, string newName, string newPhone, int newGroup);
    void displayContacts();
};
#endif // CONTACTBOOK_H