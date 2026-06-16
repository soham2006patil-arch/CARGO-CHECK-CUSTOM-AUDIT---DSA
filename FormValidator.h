
#ifndef FORMVALIDATOR_H
#define FORMVALIDATOR_H

#include <unordered_set>
#include <iostream>
using namespace std;

class FormValidator {
private:
    unordered_set<string> forms;

public:
    void addValidForm(string id);
    void validateForm(string id);
};

#endif
