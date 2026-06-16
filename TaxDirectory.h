
#ifndef TAXDIRECTORY_H
#define TAXDIRECTORY_H

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isEnd;
    string category;

    TrieNode();
};

class TaxDirectory {
private:
    TrieNode* root;
    void displayAll(TrieNode* node, string prefix);

public:
    TaxDirectory();
    void insertCode(string code, string category);
    void searchPrefix(string prefix);
};

#endif
