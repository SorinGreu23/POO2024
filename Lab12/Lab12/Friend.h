#ifndef FRIEND_H
#define FRIEND_H

#include "Contact.h"

class Friend : public Contact {
    std::string dateOfBirth;
    std::string phoneNumber;
    std::string address;

public:
    Friend(const std::string& n, const std::string& dob, const std::string& ph, const std::string& addr);
    ContactType getType() const override;
};

#endif // FRIEND_H
