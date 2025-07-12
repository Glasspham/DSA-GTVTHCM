#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "element.h"
class linkedlist
{
private:
    element *head;
    element *tail;
    int nNum;

public:
    linkedlist();
    virtual ~linkedlist();
    element *Gethead() { return head; }
    void Sethead(element *val) { head = val; }
    element *Gettail() { return tail; }
    void Settail(element *val) { tail = val; }
    void InsertFirst(element *);
    void InsertTail(element *);
    void InsertFirstUnique(element *);
    void InsertTailUnique(element *);
    void insertAfter(element *, element *);
    bool DeleteFirst();
    bool DeleteLast();
    bool DeleteAfter(element *);
    void RemoveAll();
    void Travel();
    int SumList();
    int MaxList();
    int CountPrime();
    int CountX(int);
    void splitList(int, linkedlist &, linkedlist &);
protected:
};
#endif // LINKEDLIST_H