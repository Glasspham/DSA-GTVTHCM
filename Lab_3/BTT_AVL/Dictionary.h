#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "AVL_tree.h"
#include <string>
using namespace std;
class Dictionary {
public:
    Dictionary();
    ~Dictionary();
    void addWord(string, string);
    bool lookupWord(string, string&) ;
    bool modifyWord(string, string);
    void displayAll() ;

private:
    AVL_tree tree;
};

#endif // DICTIONARY_H