#pragma once
#ifndef _WORD_H_
#define _WORD_H_
#include <string>
using namespace std;

class Word {
private:
    string wordEnglish;
    string wordVietnamese;
public:
    Word() : wordEnglish(""), wordVietnamese("") {}
    Word(string e, string v) : wordEnglish(e), wordVietnamese(v) {}
    string getWordEnglish() const { return wordEnglish; }
    string getWordVietnamese() const { return wordVietnamese; }
    void setWordEnglish(const string& e) { wordEnglish = e; }
    void setWordVietnamese(const string& v) { wordVietnamese = v; }
    bool operator==(const Word& other) const { return wordEnglish == other.wordEnglish; }
    bool operator!=(const Word& other) const { return wordEnglish != other.wordEnglish; }
    bool operator<(const Word& other) const { return wordEnglish < other.wordEnglish; }
    bool operator>(const Word& other) const { return wordEnglish > other.wordEnglish; }
    bool operator<=(const Word& other) const { return wordEnglish <= other.wordEnglish; }
    bool operator>=(const Word& other) const { return wordEnglish >= other.wordEnglish; }
};
#endif // _WORD_H_