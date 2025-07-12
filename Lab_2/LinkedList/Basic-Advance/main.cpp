#include <iostream>
#include "linkedlist.h"
using namespace std;
int main()
{
    linkedlist *list_ = new linkedlist();
    element *e;
    e=new element(9);
    list_->InsertTail(e);
    e=new element(10);
    list_->InsertTail(e);
    e=new element(8);
    list_->InsertTail(e);
    list_->Travel();
    list_->DeleteFirst();
    cout<<"\n";
    list_->Travel();
    return 0;
}