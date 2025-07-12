#pragma once
#ifndef _LIBRARY_H_
#define _LIBRARY_H_
#include <iostream>
#include <string>
using namespace std;
const int MAX_AUTHORS = 5;
struct Book {
    string title;
    string authors[MAX_AUTHORS];
    int authorCount;
    string publisher;
    int year;
    Book* next;
    Book(string t, string p, int y) : title(t), publisher(p), year(y), authorCount(0), next(nullptr) {}
};
class Library {
private:
    Book* head;
public:
    Library();
    ~Library();
    void addBook();
    int countBooksByAuthor(string author);
    void findBooksByPublisherAndYear(string publisher, int year);
    void displayBooks();
};
#endif //_LIBRARY_H_