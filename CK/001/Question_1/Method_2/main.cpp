#include "ContactBook.h"
using namespace std;
/*
void lines() {
    cout << "--------------------------------" << endl;
}

void menu() {
    cout << "1. Insert Contact" << endl;
    cout << "2. Search Contact" << endl;
    cout << "3. Update Contact" << endl;
    cout << "4. Remove Contact" << endl;
    cout << "5. Display Contacts" << endl;
    cout << "0. Exit" << endl;
}

void Group() {
    cout << "1. Family" << endl;
    cout << "2. Company" << endl;
    cout << "3. Friend" << endl;
    cout << "4. Others" << endl;
}

int main() {
    ContactBook contactBook;
    int choice, group;
    string name, phone, key;
    do {
        menu();
        lines();
        cout << "Enter choice: ";
        cin >> choice;
        lines();
        cin.ignore();
        switch (choice) {
        case 0:
            cout << "Goodbye!" << endl;
            break;
        case 1:{
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone: ";
                cin >> phone;
                do {
                    Group();
                    cout << "Group: ";
                    cin >> group;
                    if (group < 1 || group > 4)
                        cout << "Invalid group!" << endl;
                } while (group < 1 || group > 4);
                contactBook.addContact(name, phone, group);
            }
            lines();
            break;
        case 2:{
                cout << "Enter name or phone: ";
                getline(cin, key);
                contactBook.search(key);
            }
            lines();
            break;
        case 3:{
                cout << "Enter name or phone: ";
                getline(cin, key);
                cout << "Enter new name: ";
                getline(cin, name);
                cout << "Enter new phone: ";
                cin >> phone;
                do {
                    Group();
                    cout << "Group: ";
                    cin >> group;
                    if (group < 1 || group > 4)
                        cout << "Invalid group!" << endl;
                } while (group < 1 || group > 4);
                contactBook.updateContact(key, name, phone, group);
            }
            lines();
            break;
        case 4:{
                cout << "Enter name or phone: ";
                getline(cin, key);
                contactBook.removeContact(key);
            }
            lines();
            break;
        case 5:
            contactBook.displayContacts();
            lines();
            break;
        default:
            cout << "Invalid choice!" << endl;
            lines();
            break;
        }
    } while(choice != 0);
    return 0;
}
 */

 // --- Test Function --- //
int main() {
    ContactBook contactBook;
    contactBook.addContact("John Doe", "0123456789", 1);
    contactBook.addContact("Jane Doe", "0987654321", 2);
    contactBook.addContact("Alice", "0123455789", 3);
    contactBook.addContact("Bob", "0977654321", 4);
    contactBook.addContact("Charlie", "0123446789", 4);

    cout << "--- Display ---" << endl;
    contactBook.displayContacts();

    cout << "--- Search ---" << endl;
    cout << "Search by name: John Doe" << endl;
    Contact* result = contactBook.search("John Doe");
    if (result != nullptr) result->display();
    else cout << "Not found!" << endl;
    
    cout << "Search by phone: 0987654321" << endl;
    result = contactBook.search("0987654321");
    if (result != nullptr) result->display();
    else cout << "Not found!" << endl;

    cout << "--- Update ---" << endl;
    contactBook.updateContact("John Doe", "John Hello", "0987654321", 2);
    cout << "Print list after update" << endl;
    contactBook.displayContacts();

    cout << "--- Remove ---" << endl;
    contactBook.removeContact("Jane Doe");
    cout << "Print list after remove" << endl;
    contactBook.displayContacts();
}