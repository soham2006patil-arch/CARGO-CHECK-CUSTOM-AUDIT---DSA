
#include "TaxDirectory.h"

TrieNode::TrieNode() {
    isEnd = false;
}

TaxDirectory::TaxDirectory() {
    root = new TrieNode();
}

void TaxDirectory::insertCode(string code, string category) {
    TrieNode* current = root;

    for(char c : code) {
        if(current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }

    current->isEnd = true;
    current->category = category;
}

void TaxDirectory::displayAll(TrieNode* node, string prefix) {
    if(node->isEnd) {
        cout << prefix << " - " << node->category << endl;
    }

    for(auto pair : node->children) {
        displayAll(pair.second, prefix + pair.first);
    }
}

void TaxDirectory::searchPrefix(string prefix) {
    TrieNode* current = root;

    for(char c : prefix) {
        if(current->children.find(c) == current->children.end()) {
            cout << "No matching codes found\n";
            return;
        }
        current = current->children[c];
    }

    displayAll(current, prefix);
}
