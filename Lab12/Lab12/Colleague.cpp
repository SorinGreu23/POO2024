#include "Colleague.h"

Colleague::Colleague(const std::string& n, const std::string& ph, const std::string& comp, const std::string& addr)
    : Contact(n), phoneNumber(ph), company(comp), address(addr) {}

ContactType Colleague::getType() const {
    return ContactType::Colleague;
}