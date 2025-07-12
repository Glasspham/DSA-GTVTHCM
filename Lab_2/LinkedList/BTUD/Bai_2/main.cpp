#include"Library.h"

void menu() {
    cout << "\n============== MENU ==============\n";
    cout << "1. Them sach\n";
    cout << "2. Hien thi sach\n";
    cout << "3. Dem so sach cua mot tac gia\n";
    cout << "4. Tim sach theo nam va NXB\n";
    cout << "0. Thoat\n";
    cout << "Lua chon: ";
}

int main() {
    Library lib;
    int choice;
    do {
        menu();
        cin >> choice;
        cout << "---------------------------------\n";
        switch (choice) {
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.displayBooks();
                break;
            case 3: {
                cin.ignore();
                cout << "Nhap ten tac gia: ";
                string author; getline(cin, author);
                cout << "So sach cua tac gia " << author << ": " << lib.countBooksByAuthor(author) << endl;
                break;
            }
            case 4: {
                cout << "Nhap nam xuat ban: ";
                int year; cin >> year;
                cin.ignore();
                cout << "Nhap nha xuat ban: ";
                string publisher; getline(cin, publisher);
                cout << "Cac sach cua NXB " << publisher << " trong nam " << year << ":\n";
                lib.findBooksByPublisherAndYear(publisher, year);
                break;
            }
            case 0:
                cout << "Thoat chuong trinh...\n";
                break;
            default: 
                cout << "Lua chon khong hop le!\n";
                break;
        }
    } while (choice != 0);
    return 0;
}
