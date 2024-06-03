#include "Acquaintance.h"

Acquaintance::Acquaintance(const std::string& n, const std::string& ph)
    : Contact(n), phoneNumber(ph) {}

ContactType Acquaintance::getType() const {
    return ContactType::Acquaintance;
}
