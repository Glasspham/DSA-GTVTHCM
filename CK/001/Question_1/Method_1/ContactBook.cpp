#include "ContactBook.h"

// ----Function Helper---- //
bool CheckPhone(string str) {
    for(char c : str)
        if(!isdigit(c)) return false;
    return true;
}

// ----Class ContactBook---- //
void ContactBook::insert(Contact contact) {
    if(treeByPhone.search(contact.getPhone())) {
        cout << "Phone number already exists" << endl;
        return;
    }
    if(treeByName.search(contact.getName())) {
        cout << "Name already exists" << endl;
        return;
    }
    treeByPhone.insert(contact);
    treeByName.insert(contact);
}

void ContactBook::search(string key) {
    Contact *contact;
    if(CheckPhone(key)) 
        contact = treeByPhone.search(key);
    else contact = treeByName.search(key);
    if(contact) {
        cout << "Name: " << contact->getName() << "Phone: " << contact->getPhone() << " Group: ";
        int i = contact->getGroup();
        if(i == 1) cout << "Family" << endl;
        else if(i == 2) cout << "Company" << endl;
        else if(i == 3) cout << "Friend" << endl;
        else cout << "Other" << endl;
    } else cout << "Contact not found" << endl;
}

void ContactBook::update(string key, Contact newContact) {
    bool isPhone = CheckPhone(key);
    Contact *oldContact;
    if(isPhone) oldContact = treeByPhone.search(key);
    else oldContact = treeByName.search(key);
    if(!oldContact) {
        cout << "Contact not found" << endl;
        return;
    }
    if(treeByPhone.search(newContact.getPhone()) && newContact.getPhone() != oldContact->getPhone()) {
        cout << "Phone number already exists" << endl;
        return;
    }
    if(treeByName.search(newContact.getName()) && newContact.getName() != oldContact->getName()) {
        cout << "Name already exists" << endl;
        return;
    }
    if(isPhone) {
        treeByPhone.update(key, newContact);
        treeByName.update(oldContact->getName(), newContact);
    } else {
        treeByName.update(key, newContact);
        treeByPhone.update(oldContact->getPhone(), newContact);
    }
}

void ContactBook::remove(string key) {
    Contact *contact;
    bool isPhone = CheckPhone(key);
    if(isPhone) contact = treeByPhone.search(key);
    else contact = treeByName.search(key);
    if(contact) {
        if (isPhone) {
            treeByPhone.remove(key);
            treeByName.remove(contact->getName());
        } else {
            treeByName.remove(key);
            treeByPhone.remove(contact->getPhone());
        }
    } else cout << "Contact not found" << endl;
}

void ContactBook::display() { treeByName.display(); }