#include "Friend.h"

Friend::Friend(const std::string& n, const std::string& dob, const std::string& ph, const std::string& addr)
    : Contact(n), dateOfBirth(dob), phoneNumber(ph), address(addr) {}

ContactType Friend::getType() const {
    return ContactType::Friend;
}
