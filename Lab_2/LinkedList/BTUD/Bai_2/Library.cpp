#include "Library.h"

Library::Library() { head = nullptr; }

Library::~Library() {
    while (head) {
        Book* temp = head;
        head = head->next;
        delete temp;
    }
}

void Library::addBook() {
    string title, publisher;
    int year, numAuthors;
    cin.ignore();
    cout << "Nhap ten sach: ";
    getline(cin, title);
    cout << "Nhap so luong tac gia (toi da 5): ";
    cin >> numAuthors;
    cin.ignore();
    if (numAuthors > MAX_AUTHORS) numAuthors = MAX_AUTHORS;
    string authors[MAX_AUTHORS];
    for (int i = 0; i < numAuthors; i++) {
        cout << "Nhap ten tac gia " << i + 1 << ": ";
        getline(cin, authors[i]);
    }
    cout << "Nhap nha xuat ban: ";
    getline(cin, publisher);
    cout << "Nhap nam xuat ban: ";
    cin >> year;
    Book* newBook = new Book(title, publisher, year);
    newBook->authorCount = numAuthors;
    for (int i = 0; i < numAuthors; i++) newBook->authors[i] = authors[i];
    newBook->next = head;
    head = newBook;
}

int Library::countBooksByAuthor(string author) {
    int count = 0;
    Book* temp = head;
    while (temp) {
        for (int i = 0; i < temp->authorCount; i++) {
            if (temp->authors[i] == author) {
                count++;
                break;
            }
        }
        temp = temp->next;
    }
    return count;
}

void Library::findBooksByPublisherAndYear(string publisher, int year) {
    Book* temp = head;
    bool found = false;
    while (temp) {
        if (temp->publisher == publisher && temp->year == year) {
            cout << "- " << temp->title << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "Khong co sach nao duoc tim thay!" << endl;
}

void Library::displayBooks() {
    Book* temp = head;
    while (temp) {
        cout << "Ten sach: " << temp->title << "\nTac gia: ";
        for (int i = 0; i < temp->authorCount; i++) {
            cout << temp->authors[i];
            if (i < temp->authorCount - 1) cout << ", ";
        }
        cout << "\nNha xuat ban: " << temp->publisher << "\nNam xuat ban: " << temp->year << endl;
        cout << "---------------------------------\n";
        temp = temp->next;
    }
}