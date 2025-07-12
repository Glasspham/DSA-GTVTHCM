#include "Dictionary.h"
#include <fstream>
#include <iostream>

Dictionary::Dictionary() {}

Dictionary::~Dictionary() {}

void Dictionary::addWord(string english, string vietnamese) {
    Word word(english, vietnamese);
    tree.insert(word);
}

bool Dictionary::lookupWord(string english, string& vietnamese) {
    return tree.search(english, vietnamese);
}

bool Dictionary::modifyWord(string english, string new_vietnamese) {
    return tree.modify(english, new_vietnamese);
}

void Dictionary::displayAll() {
    tree.TravelLNR();
}