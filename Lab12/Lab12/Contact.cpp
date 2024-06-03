#include "Contact.h"

Contact::Contact(const std::string& n) : name(n) {}

std::string Contact::getName() const {
    return name;
}
