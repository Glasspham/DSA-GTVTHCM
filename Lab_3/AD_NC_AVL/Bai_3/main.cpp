#include <iostream>
#include "AVL_tree.h"
#include "Student.h"
using namespace std;
int main() {
    AVL_tree tree;
    // Inserting some students
    tree.insert(Student(101, "An", "2002-05-15", 3.0));
    tree.insert(Student(102, "Bo", "2003-02-28", 3.6));
    tree.insert(Student(103, "Ca", "2004-10-10", 3.7));
    tree.insert(Student(104, "De", "2005-06-20", 2.9));
    tree.TravelLNR();
    cout << "-------------\n";
    tree.TravelNLR();
    cout << "-------------\n";
    int search_id = 102;
    bool found = tree.search(search_id);
    if (found) cout << "Student with ID " << search_id << " found in the AVL tree." << endl;
    else cout << "Student with ID " << search_id << " not found in the AVL tree." << endl;
    cout << "-------------\n";
    int del_id = 103;
    tree.deleteNode(del_id);
    tree.TravelLNR();
    cout << "-------------\n";
    return 0;
}
