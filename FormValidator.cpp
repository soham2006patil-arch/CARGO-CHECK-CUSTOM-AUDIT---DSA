
#include "FormValidator.h"

void FormValidator::addValidForm(string id) {
    forms.insert(id);
}

void FormValidator::validateForm(string id) {
    if(forms.find(id) != forms.end()) {
        cout << "Valid Form\n";
    } else {
        cout << "Invalid Form\n";
    }
}
