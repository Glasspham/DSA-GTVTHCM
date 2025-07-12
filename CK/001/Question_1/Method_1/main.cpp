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
                contactBook.insert(Contact(name, phone, group));
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
                cout << "Group: ";
                cin >> group;
                contactBook.update(key, Contact(name, phone, group));
            }
            lines();
            break;
        case 4:{
                cout << "Enter name or phone: ";
                getline(cin, key);
                contactBook.remove(key);
            }
            lines();
            break;
        case 5:
            contactBook.display();
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
    contactBook.insert(Contact("John Doe", "0123456789", 1));
    contactBook.insert(Contact("Jane Doe", "0987654321", 2));
    contactBook.insert(Contact("Alice", "0123455789", 3));
    contactBook.insert(Contact("Bob", "0977654321", 4));
    contactBook.insert(Contact("Charlie", "0123446789", 4));
    cout << "--- Display ---" << endl;
    contactBook.display();

    cout << "--- Search ---" << endl;
    cout << "Search by name: John Doe" << endl;
    contactBook.search("John Doe"); 
    cout << "Search by phone: 0987654321" << endl;
    contactBook.search("0987654321");

    cout << "--- Update ---" << endl;
    contactBook.update("John Doe", Contact("John Hello", "0123456789", 2));
    cout << "Print list after update" << endl;
    contactBook.display();

    cout << "--- Remove ---" << endl;
    contactBook.remove("Jane Doe");
    cout << "Print list after remove" << endl;
    contactBook.display();
}